#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_cluster_role.h"
#include "../model/v1alpha1_cluster_role_binding.h"
#include "../model/v1alpha1_cluster_role_binding_list.h"
#include "../model/v1alpha1_cluster_role_list.h"
#include "../model/v1alpha1_role.h"
#include "../model/v1alpha1_role_binding.h"
#include "../model/v1alpha1_role_binding_list.h"
#include "../model/v1alpha1_role_list.h"


// create a ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_createClusterRole(apiClient_t *apiClient, v1alpha1_cluster_role_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_createClusterRoleBinding(apiClient_t *apiClient, v1alpha1_cluster_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_createNamespacedRole(apiClient_t *apiClient, char * _namespace , v1alpha1_role_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_createNamespacedRoleBinding(apiClient_t *apiClient, char * _namespace , v1alpha1_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete a ClusterRole
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteClusterRole(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteClusterRoleBinding(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete collection of ClusterRole
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteCollectionClusterRole(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteCollectionClusterRoleBinding(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Role
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteCollectionNamespacedRole(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of RoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteCollectionNamespacedRoleBinding(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete a Role
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteNamespacedRole(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a RoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
RbacAuthorizationV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind ClusterRole
//
v1alpha1_cluster_role_list_t*
RbacAuthorizationV1alpha1API_listClusterRole(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind ClusterRoleBinding
//
v1alpha1_cluster_role_binding_list_t*
RbacAuthorizationV1alpha1API_listClusterRoleBinding(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind Role
//
v1alpha1_role_list_t*
RbacAuthorizationV1alpha1API_listNamespacedRole(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind RoleBinding
//
v1alpha1_role_binding_list_t*
RbacAuthorizationV1alpha1API_listNamespacedRoleBinding(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind RoleBinding
//
v1alpha1_role_binding_list_t*
RbacAuthorizationV1alpha1API_listRoleBindingForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind Role
//
v1alpha1_role_list_t*
RbacAuthorizationV1alpha1API_listRoleForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// partially update the specified ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_patchClusterRole(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_patchClusterRoleBinding(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_patchNamespacedRole(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_patchNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_readClusterRole(apiClient_t *apiClient, char * name , char * pretty );


// read the specified ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_readClusterRoleBinding(apiClient_t *apiClient, char * name , char * pretty );


// read the specified Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_readNamespacedRole(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_readNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_replaceClusterRole(apiClient_t *apiClient, char * name , v1alpha1_cluster_role_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_replaceClusterRoleBinding(apiClient_t *apiClient, char * name , v1alpha1_cluster_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_replaceNamespacedRole(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_role_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_replaceNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager );


