#include <proj.h>

void transform(const char* source) {
    PJ* pj = proj_create_crs_to_crs(
        PJ_DEFAULT_CTX,
        source,
        "+proj=longlat +datum=WGS84 +no_defs",
        NULL
    );

    for (double y = 6494900; y > 6484900; y -= 1.0) {
        for (double x = 2654600; x < 2655100; x += 1.0) {
            PJ_COORD coord;
            coord.xy = {x, y};
            proj_trans(pj, PJ_FWD, coord);
        }
    }

    proj_destroy(pj);
}

int main() {
    // fast
    // https://epsg.io/27200
    // transform("+proj=nzmg +lat_0=-41 +lon_0=173 +x_0=2510000 +y_0=6023150 +ellps=intl +towgs84=59.47,-5.04,187.44,0.47,-0.1,1.024,-4.5993 +units=m +no_defs");

    // fast with proj 6, slow with proj 8
    // https://spatialreference.org/ref/epsg/27200/proj4/
    transform("+proj=nzmg +lat_0=-41 +lon_0=173 +x_0=2510000 +y_0=6023150 +ellps=intl +datum=nzgd49 +units=m +no_defs ");
    return 0;
}
