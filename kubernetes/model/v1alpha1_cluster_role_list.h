/*
 * v1alpha1_cluster_role_list.h
 *
 * ClusterRoleList is a collection of ClusterRoles. Deprecated in v1.17 in favor of rbac.authorization.k8s.io/v1 ClusterRoles, and will no longer be served in v1.22.
 */

#ifndef _v1alpha1_cluster_role_list_H_
#define _v1alpha1_cluster_role_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_cluster_role_list_t v1alpha1_cluster_role_list_t;

#include "v1_list_meta.h"
#include "v1alpha1_cluster_role.h"



typedef struct v1alpha1_cluster_role_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1alpha1_cluster_role_list_t;

v1alpha1_cluster_role_list_t *v1alpha1_cluster_role_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1alpha1_cluster_role_list_free(v1alpha1_cluster_role_list_t *v1alpha1_cluster_role_list);

v1alpha1_cluster_role_list_t *v1alpha1_cluster_role_list_parseFromJSON(cJSON *v1alpha1_cluster_role_listJSON);

cJSON *v1alpha1_cluster_role_list_convertToJSON(v1alpha1_cluster_role_list_t *v1alpha1_cluster_role_list);

#endif /* _v1alpha1_cluster_role_list_H_ */

