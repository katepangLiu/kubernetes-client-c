#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_load_balancer_ingress.h"



v1_load_balancer_ingress_t *v1_load_balancer_ingress_create(
    char *hostname,
    char *ip,
    list_t *ports
    ) {
    v1_load_balancer_ingress_t *v1_load_balancer_ingress_local_var = malloc(sizeof(v1_load_balancer_ingress_t));
    if (!v1_load_balancer_ingress_local_var) {
        return NULL;
    }
    v1_load_balancer_ingress_local_var->hostname = hostname;
    v1_load_balancer_ingress_local_var->ip = ip;
    v1_load_balancer_ingress_local_var->ports = ports;

    return v1_load_balancer_ingress_local_var;
}


void v1_load_balancer_ingress_free(v1_load_balancer_ingress_t *v1_load_balancer_ingress) {
    if(NULL == v1_load_balancer_ingress){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_load_balancer_ingress->hostname) {
        free(v1_load_balancer_ingress->hostname);
        v1_load_balancer_ingress->hostname = NULL;
    }
    if (v1_load_balancer_ingress->ip) {
        free(v1_load_balancer_ingress->ip);
        v1_load_balancer_ingress->ip = NULL;
    }
    if (v1_load_balancer_ingress->ports) {
        list_ForEach(listEntry, v1_load_balancer_ingress->ports) {
            v1_port_status_free(listEntry->data);
        }
        list_free(v1_load_balancer_ingress->ports);
        v1_load_balancer_ingress->ports = NULL;
    }
    free(v1_load_balancer_ingress);
}

cJSON *v1_load_balancer_ingress_convertToJSON(v1_load_balancer_ingress_t *v1_load_balancer_ingress) {
    cJSON *item = cJSON_CreateObject();

    // v1_load_balancer_ingress->hostname
    if(v1_load_balancer_ingress->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1_load_balancer_ingress->hostname) == NULL) {
    goto fail; //String
    }
     } 


    // v1_load_balancer_ingress->ip
    if(v1_load_balancer_ingress->ip) { 
    if(cJSON_AddStringToObject(item, "ip", v1_load_balancer_ingress->ip) == NULL) {
    goto fail; //String
    }
     } 


    // v1_load_balancer_ingress->ports
    if(v1_load_balancer_ingress->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_load_balancer_ingress->ports) {
    list_ForEach(portsListEntry, v1_load_balancer_ingress->ports) {
    cJSON *itemLocal = v1_port_status_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
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

v1_load_balancer_ingress_t *v1_load_balancer_ingress_parseFromJSON(cJSON *v1_load_balancer_ingressJSON){

    v1_load_balancer_ingress_t *v1_load_balancer_ingress_local_var = NULL;

    // v1_load_balancer_ingress->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1_load_balancer_ingressJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1_load_balancer_ingress->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_load_balancer_ingressJSON, "ip");
    if (ip) { 
    if(!cJSON_IsString(ip))
    {
    goto end; //String
    }
    }

    // v1_load_balancer_ingress->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_load_balancer_ingressJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1_port_status_t *portsItem = v1_port_status_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }


    v1_load_balancer_ingress_local_var = v1_load_balancer_ingress_create (
        hostname ? strdup(hostname->valuestring) : NULL,
        ip ? strdup(ip->valuestring) : NULL,
        ports ? portsList : NULL
        );

    return v1_load_balancer_ingress_local_var;
end:
    return NULL;

}
