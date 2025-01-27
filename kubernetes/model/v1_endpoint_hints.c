#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_hints.h"



v1_endpoint_hints_t *v1_endpoint_hints_create(
    list_t *for_zones
    ) {
    v1_endpoint_hints_t *v1_endpoint_hints_local_var = malloc(sizeof(v1_endpoint_hints_t));
    if (!v1_endpoint_hints_local_var) {
        return NULL;
    }
    v1_endpoint_hints_local_var->for_zones = for_zones;

    return v1_endpoint_hints_local_var;
}


void v1_endpoint_hints_free(v1_endpoint_hints_t *v1_endpoint_hints) {
    if(NULL == v1_endpoint_hints){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint_hints->for_zones) {
        list_ForEach(listEntry, v1_endpoint_hints->for_zones) {
            v1_for_zone_free(listEntry->data);
        }
        list_free(v1_endpoint_hints->for_zones);
        v1_endpoint_hints->for_zones = NULL;
    }
    free(v1_endpoint_hints);
}

cJSON *v1_endpoint_hints_convertToJSON(v1_endpoint_hints_t *v1_endpoint_hints) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint_hints->for_zones
    if(v1_endpoint_hints->for_zones) { 
    cJSON *for_zones = cJSON_AddArrayToObject(item, "forZones");
    if(for_zones == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *for_zonesListEntry;
    if (v1_endpoint_hints->for_zones) {
    list_ForEach(for_zonesListEntry, v1_endpoint_hints->for_zones) {
    cJSON *itemLocal = v1_for_zone_convertToJSON(for_zonesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(for_zones, itemLocal);
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_endpoint_hints_t *v1_endpoint_hints_parseFromJSON(cJSON *v1_endpoint_hintsJSON){

    v1_endpoint_hints_t *v1_endpoint_hints_local_var = NULL;

    // v1_endpoint_hints->for_zones
    cJSON *for_zones = cJSON_GetObjectItemCaseSensitive(v1_endpoint_hintsJSON, "forZones");
    list_t *for_zonesList;
    if (for_zones) { 
    cJSON *for_zones_local_nonprimitive;
    if(!cJSON_IsArray(for_zones)){
        goto end; //nonprimitive container
    }

    for_zonesList = list_create();

    cJSON_ArrayForEach(for_zones_local_nonprimitive,for_zones )
    {
        if(!cJSON_IsObject(for_zones_local_nonprimitive)){
            goto end;
        }
        v1_for_zone_t *for_zonesItem = v1_for_zone_parseFromJSON(for_zones_local_nonprimitive);

        list_addElement(for_zonesList, for_zonesItem);
    }
    }


    v1_endpoint_hints_local_var = v1_endpoint_hints_create (
        for_zones ? for_zonesList : NULL
        );

    return v1_endpoint_hints_local_var;
end:
    return NULL;

}
