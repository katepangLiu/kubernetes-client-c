#ifndef v1beta1_endpoint_hints_TEST
#define v1beta1_endpoint_hints_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_endpoint_hints_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_endpoint_hints.h"
v1beta1_endpoint_hints_t* instantiate_v1beta1_endpoint_hints(int include_optional);



v1beta1_endpoint_hints_t* instantiate_v1beta1_endpoint_hints(int include_optional) {
  v1beta1_endpoint_hints_t* v1beta1_endpoint_hints = NULL;
  if (include_optional) {
    v1beta1_endpoint_hints = v1beta1_endpoint_hints_create(
      list_create()
    );
  } else {
    v1beta1_endpoint_hints = v1beta1_endpoint_hints_create(
      list_create()
    );
  }

  return v1beta1_endpoint_hints;
}


#ifdef v1beta1_endpoint_hints_MAIN

void test_v1beta1_endpoint_hints(int include_optional) {
    v1beta1_endpoint_hints_t* v1beta1_endpoint_hints_1 = instantiate_v1beta1_endpoint_hints(include_optional);

	cJSON* jsonv1beta1_endpoint_hints_1 = v1beta1_endpoint_hints_convertToJSON(v1beta1_endpoint_hints_1);
	printf("v1beta1_endpoint_hints :\n%s\n", cJSON_Print(jsonv1beta1_endpoint_hints_1));
	v1beta1_endpoint_hints_t* v1beta1_endpoint_hints_2 = v1beta1_endpoint_hints_parseFromJSON(jsonv1beta1_endpoint_hints_1);
	cJSON* jsonv1beta1_endpoint_hints_2 = v1beta1_endpoint_hints_convertToJSON(v1beta1_endpoint_hints_2);
	printf("repeating v1beta1_endpoint_hints:\n%s\n", cJSON_Print(jsonv1beta1_endpoint_hints_2));
}

int main() {
  test_v1beta1_endpoint_hints(1);
  test_v1beta1_endpoint_hints(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_endpoint_hints_MAIN
#endif // v1beta1_endpoint_hints_TEST
