/*
 * v1beta1_service_account_subject.h
 *
 * ServiceAccountSubject holds detailed information for service-account-kind subject.
 */

#ifndef _v1beta1_service_account_subject_H_
#define _v1beta1_service_account_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_service_account_subject_t v1beta1_service_account_subject_t;




typedef struct v1beta1_service_account_subject_t {
    char *name; // string
    char *_namespace; // string

} v1beta1_service_account_subject_t;

v1beta1_service_account_subject_t *v1beta1_service_account_subject_create(
    char *name,
    char *_namespace
);

void v1beta1_service_account_subject_free(v1beta1_service_account_subject_t *v1beta1_service_account_subject);

v1beta1_service_account_subject_t *v1beta1_service_account_subject_parseFromJSON(cJSON *v1beta1_service_account_subjectJSON);

cJSON *v1beta1_service_account_subject_convertToJSON(v1beta1_service_account_subject_t *v1beta1_service_account_subject);

#endif /* _v1beta1_service_account_subject_H_ */

