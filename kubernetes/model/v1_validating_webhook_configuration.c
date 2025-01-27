#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validating_webhook_configuration.h"



v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *webhooks
    ) {
    v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_local_var = malloc(sizeof(v1_validating_webhook_configuration_t));
    if (!v1_validating_webhook_configuration_local_var) {
        return NULL;
    }
    v1_validating_webhook_configuration_local_var->api_version = api_version;
    v1_validating_webhook_configuration_local_var->kind = kind;
    v1_validating_webhook_configuration_local_var->metadata = metadata;
    v1_validating_webhook_configuration_local_var->webhooks = webhooks;

    return v1_validating_webhook_configuration_local_var;
}


void v1_validating_webhook_configuration_free(v1_validating_webhook_configuration_t *v1_validating_webhook_configuration) {
    if(NULL == v1_validating_webhook_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validating_webhook_configuration->api_version) {
        free(v1_validating_webhook_configuration->api_version);
        v1_validating_webhook_configuration->api_version = NULL;
    }
    if (v1_validating_webhook_configuration->kind) {
        free(v1_validating_webhook_configuration->kind);
        v1_validating_webhook_configuration->kind = NULL;
    }
    if (v1_validating_webhook_configuration->metadata) {
        v1_object_meta_free(v1_validating_webhook_configuration->metadata);
        v1_validating_webhook_configuration->metadata = NULL;
    }
    if (v1_validating_webhook_configuration->webhooks) {
        list_ForEach(listEntry, v1_validating_webhook_configuration->webhooks) {
            v1_validating_webhook_free(listEntry->data);
        }
        list_free(v1_validating_webhook_configuration->webhooks);
        v1_validating_webhook_configuration->webhooks = NULL;
    }
    free(v1_validating_webhook_configuration);
}

cJSON *v1_validating_webhook_configuration_convertToJSON(v1_validating_webhook_configuration_t *v1_validating_webhook_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_validating_webhook_configuration->api_version
    if(v1_validating_webhook_configuration->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_validating_webhook_configuration->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_validating_webhook_configuration->kind
    if(v1_validating_webhook_configuration->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_validating_webhook_configuration->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_validating_webhook_configuration->metadata
    if(v1_validating_webhook_configuration->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_validating_webhook_configuration->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_validating_webhook_configuration->webhooks
    if(v1_validating_webhook_configuration->webhooks) { 
    cJSON *webhooks = cJSON_AddArrayToObject(item, "webhooks");
    if(webhooks == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *webhooksListEntry;
    if (v1_validating_webhook_configuration->webhooks) {
    list_ForEach(webhooksListEntry, v1_validating_webhook_configuration->webhooks) {
    cJSON *itemLocal = v1_validating_webhook_convertToJSON(webhooksListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(webhooks, itemLocal);
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

v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_parseFromJSON(cJSON *v1_validating_webhook_configurationJSON){

    v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_local_var = NULL;

    // define the local variable for v1_validating_webhook_configuration->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1_validating_webhook_configuration->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_validating_webhook_configuration->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_validating_webhook_configuration->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_validating_webhook_configuration->webhooks
    cJSON *webhooks = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "webhooks");
    list_t *webhooksList;
    if (webhooks) { 
    cJSON *webhooks_local_nonprimitive;
    if(!cJSON_IsArray(webhooks)){
        goto end; //nonprimitive container
    }

    webhooksList = list_create();

    cJSON_ArrayForEach(webhooks_local_nonprimitive,webhooks )
    {
        if(!cJSON_IsObject(webhooks_local_nonprimitive)){
            goto end;
        }
        v1_validating_webhook_t *webhooksItem = v1_validating_webhook_parseFromJSON(webhooks_local_nonprimitive);

        list_addElement(webhooksList, webhooksItem);
    }
    }


    v1_validating_webhook_configuration_local_var = v1_validating_webhook_configuration_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        webhooks ? webhooksList : NULL
        );

    return v1_validating_webhook_configuration_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
