#include "connect4.h"

void free_exit(t_data* data)
{
    size_t height;

    height = 0;
    while(height < data->cell_height)
    {
        free(data->cell_grid[height]);
        height++;
    }
    free(data->cell_grid);
    exit(0);
}