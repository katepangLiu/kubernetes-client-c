#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_horizontal_pod_autoscaler_spec.h"



v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_create(
    v2beta2_horizontal_pod_autoscaler_behavior_t *behavior,
    int max_replicas,
    list_t *metrics,
    int min_replicas,
    v2beta2_cross_version_object_reference_t *scale_target_ref
    ) {
    v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_local_var = malloc(sizeof(v2beta2_horizontal_pod_autoscaler_spec_t));
    if (!v2beta2_horizontal_pod_autoscaler_spec_local_var) {
        return NULL;
    }
    v2beta2_horizontal_pod_autoscaler_spec_local_var->behavior = behavior;
    v2beta2_horizontal_pod_autoscaler_spec_local_var->max_replicas = max_replicas;
    v2beta2_horizontal_pod_autoscaler_spec_local_var->metrics = metrics;
    v2beta2_horizontal_pod_autoscaler_spec_local_var->min_replicas = min_replicas;
    v2beta2_horizontal_pod_autoscaler_spec_local_var->scale_target_ref = scale_target_ref;

    return v2beta2_horizontal_pod_autoscaler_spec_local_var;
}


void v2beta2_horizontal_pod_autoscaler_spec_free(v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec) {
    if(NULL == v2beta2_horizontal_pod_autoscaler_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_horizontal_pod_autoscaler_spec->behavior) {
        v2beta2_horizontal_pod_autoscaler_behavior_free(v2beta2_horizontal_pod_autoscaler_spec->behavior);
        v2beta2_horizontal_pod_autoscaler_spec->behavior = NULL;
    }
    if (v2beta2_horizontal_pod_autoscaler_spec->metrics) {
        list_ForEach(listEntry, v2beta2_horizontal_pod_autoscaler_spec->metrics) {
            v2beta2_metric_spec_free(listEntry->data);
        }
        list_free(v2beta2_horizontal_pod_autoscaler_spec->metrics);
        v2beta2_horizontal_pod_autoscaler_spec->metrics = NULL;
    }
    if (v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref) {
        v2beta2_cross_version_object_reference_free(v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref);
        v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref = NULL;
    }
    free(v2beta2_horizontal_pod_autoscaler_spec);
}

cJSON *v2beta2_horizontal_pod_autoscaler_spec_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_horizontal_pod_autoscaler_spec->behavior
    if(v2beta2_horizontal_pod_autoscaler_spec->behavior) { 
    cJSON *behavior_local_JSON = v2beta2_horizontal_pod_autoscaler_behavior_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec->behavior);
    if(behavior_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "behavior", behavior_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2beta2_horizontal_pod_autoscaler_spec->max_replicas
    if (!v2beta2_horizontal_pod_autoscaler_spec->max_replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "maxReplicas", v2beta2_horizontal_pod_autoscaler_spec->max_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v2beta2_horizontal_pod_autoscaler_spec->metrics
    if(v2beta2_horizontal_pod_autoscaler_spec->metrics) { 
    cJSON *metrics = cJSON_AddArrayToObject(item, "metrics");
    if(metrics == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *metricsListEntry;
    if (v2beta2_horizontal_pod_autoscaler_spec->metrics) {
    list_ForEach(metricsListEntry, v2beta2_horizontal_pod_autoscaler_spec->metrics) {
    cJSON *itemLocal = v2beta2_metric_spec_convertToJSON(metricsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(metrics, itemLocal);
    }
    }
     } 


    // v2beta2_horizontal_pod_autoscaler_spec->min_replicas
    if(v2beta2_horizontal_pod_autoscaler_spec->min_replicas) { 
    if(cJSON_AddNumberToObject(item, "minReplicas", v2beta2_horizontal_pod_autoscaler_spec->min_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref
    if (!v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref) {
        goto fail;
    }
    
    cJSON *scale_target_ref_local_JSON = v2beta2_cross_version_object_reference_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref);
    if(scale_target_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleTargetRef", scale_target_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_specJSON){

    v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_local_var = NULL;

    // define the local variable for v2beta2_horizontal_pod_autoscaler_spec->behavior
    v2beta2_horizontal_pod_autoscaler_behavior_t *behavior_local_nonprim = NULL;

    // define the local variable for v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref
    v2beta2_cross_version_object_reference_t *scale_target_ref_local_nonprim = NULL;

    // v2beta2_horizontal_pod_autoscaler_spec->behavior
    cJSON *behavior = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "behavior");
    if (behavior) { 
    behavior_local_nonprim = v2beta2_horizontal_pod_autoscaler_behavior_parseFromJSON(behavior); //nonprimitive
    }

    // v2beta2_horizontal_pod_autoscaler_spec->max_replicas
    cJSON *max_replicas = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "maxReplicas");
    if (!max_replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_replicas))
    {
    goto end; //Numeric
    }

    // v2beta2_horizontal_pod_autoscaler_spec->metrics
    cJSON *metrics = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "metrics");
    list_t *metricsList;
    if (metrics) { 
    cJSON *metrics_local_nonprimitive;
    if(!cJSON_IsArray(metrics)){
        goto end; //nonprimitive container
    }

    metricsList = list_create();

    cJSON_ArrayForEach(metrics_local_nonprimitive,metrics )
    {
        if(!cJSON_IsObject(metrics_local_nonprimitive)){
            goto end;
        }
        v2beta2_metric_spec_t *metricsItem = v2beta2_metric_spec_parseFromJSON(metrics_local_nonprimitive);

        list_addElement(metricsList, metricsItem);
    }
    }

    // v2beta2_horizontal_pod_autoscaler_spec->min_replicas
    cJSON *min_replicas = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "minReplicas");
    if (min_replicas) { 
    if(!cJSON_IsNumber(min_replicas))
    {
    goto end; //Numeric
    }
    }

    // v2beta2_horizontal_pod_autoscaler_spec->scale_target_ref
    cJSON *scale_target_ref = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "scaleTargetRef");
    if (!scale_target_ref) {
        goto end;
    }

    
    scale_target_ref_local_nonprim = v2beta2_cross_version_object_reference_parseFromJSON(scale_target_ref); //nonprimitive


    v2beta2_horizontal_pod_autoscaler_spec_local_var = v2beta2_horizontal_pod_autoscaler_spec_create (
        behavior ? behavior_local_nonprim : NULL,
        max_replicas->valuedouble,
        metrics ? metricsList : NULL,
        min_replicas ? min_replicas->valuedouble : 0,
        scale_target_ref_local_nonprim
        );

    return v2beta2_horizontal_pod_autoscaler_spec_local_var;
end:
    if (behavior_local_nonprim) {
        v2beta2_horizontal_pod_autoscaler_behavior_free(behavior_local_nonprim);
        behavior_local_nonprim = NULL;
    }
    if (scale_target_ref_local_nonprim) {
        v2beta2_cross_version_object_reference_free(scale_target_ref_local_nonprim);
        scale_target_ref_local_nonprim = NULL;
    }
    return NULL;

}
