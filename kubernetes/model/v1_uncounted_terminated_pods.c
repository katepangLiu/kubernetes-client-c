#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_uncounted_terminated_pods.h"



v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_create(
    list_t *failed,
    list_t *succeeded
    ) {
    v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_local_var = malloc(sizeof(v1_uncounted_terminated_pods_t));
    if (!v1_uncounted_terminated_pods_local_var) {
        return NULL;
    }
    v1_uncounted_terminated_pods_local_var->failed = failed;
    v1_uncounted_terminated_pods_local_var->succeeded = succeeded;

    return v1_uncounted_terminated_pods_local_var;
}


void v1_uncounted_terminated_pods_free(v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods) {
    if(NULL == v1_uncounted_terminated_pods){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_uncounted_terminated_pods->failed) {
        list_ForEach(listEntry, v1_uncounted_terminated_pods->failed) {
            free(listEntry->data);
        }
        list_free(v1_uncounted_terminated_pods->failed);
        v1_uncounted_terminated_pods->failed = NULL;
    }
    if (v1_uncounted_terminated_pods->succeeded) {
        list_ForEach(listEntry, v1_uncounted_terminated_pods->succeeded) {
            free(listEntry->data);
        }
        list_free(v1_uncounted_terminated_pods->succeeded);
        v1_uncounted_terminated_pods->succeeded = NULL;
    }
    free(v1_uncounted_terminated_pods);
}

cJSON *v1_uncounted_terminated_pods_convertToJSON(v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods) {
    cJSON *item = cJSON_CreateObject();

    // v1_uncounted_terminated_pods->failed
    if(v1_uncounted_terminated_pods->failed) { 
    cJSON *failed = cJSON_AddArrayToObject(item, "failed");
    if(failed == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *failedListEntry;
    list_ForEach(failedListEntry, v1_uncounted_terminated_pods->failed) {
    if(cJSON_AddStringToObject(failed, "", (char*)failedListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_uncounted_terminated_pods->succeeded
    if(v1_uncounted_terminated_pods->succeeded) { 
    cJSON *succeeded = cJSON_AddArrayToObject(item, "succeeded");
    if(succeeded == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *succeededListEntry;
    list_ForEach(succeededListEntry, v1_uncounted_terminated_pods->succeeded) {
    if(cJSON_AddStringToObject(succeeded, "", (char*)succeededListEntry->data) == NULL)
    {
        goto fail;
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

v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_parseFromJSON(cJSON *v1_uncounted_terminated_podsJSON){

    v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_local_var = NULL;

    // v1_uncounted_terminated_pods->failed
    cJSON *failed = cJSON_GetObjectItemCaseSensitive(v1_uncounted_terminated_podsJSON, "failed");
    list_t *failedList;
    if (failed) { 
    cJSON *failed_local;
    if(!cJSON_IsArray(failed)) {
        goto end;//primitive container
    }
    failedList = list_create();

    cJSON_ArrayForEach(failed_local, failed)
    {
        if(!cJSON_IsString(failed_local))
        {
            goto end;
        }
        list_addElement(failedList , strdup(failed_local->valuestring));
    }
    }

    // v1_uncounted_terminated_pods->succeeded
    cJSON *succeeded = cJSON_GetObjectItemCaseSensitive(v1_uncounted_terminated_podsJSON, "succeeded");
    list_t *succeededList;
    if (succeeded) { 
    cJSON *succeeded_local;
    if(!cJSON_IsArray(succeeded)) {
        goto end;//primitive container
    }
    succeededList = list_create();

    cJSON_ArrayForEach(succeeded_local, succeeded)
    {
        if(!cJSON_IsString(succeeded_local))
        {
            goto end;
        }
        list_addElement(succeededList , strdup(succeeded_local->valuestring));
    }
    }


    v1_uncounted_terminated_pods_local_var = v1_uncounted_terminated_pods_create (
        failed ? failedList : NULL,
        succeeded ? succeededList : NULL
        );

    return v1_uncounted_terminated_pods_local_var;
end:
    return NULL;

}
