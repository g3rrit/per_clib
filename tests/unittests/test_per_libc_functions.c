#include "per_test_common.h"

describe(libc_functions) {
    it("per_memcpy") {
        char * a = "aaa";
        char b[3];

        per_memcpy(b, a, 3);

        asserteq_buf(a, b, 3, "");
    }

    it("per_other") {
        char * a = "aaa";
        char b[3];

        //per_memcpy(b, a, 3);

        asserteq_buf(a, b, 3, "");
    }

}


PER_TEST_MAIN