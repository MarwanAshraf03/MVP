#include "project.h"

void parse_map(int lineNumber)
{
    FILE *maps = fopen("maps", "r");
    int count = 1;
    char *map = malloc(486);

    if (maps == NULL)
        return;
    printf("line 44\n");
    while (fgets(map, 486, maps) != NULL)
    {
        if (count == lineNumber)
        {
            for (int i = 0; i < mapWidth; i++)
            {
                for (int j = 0; j < mapHeight; j++)
                {
                    worldMap[i][j] = ((int)*map) - 48;
                    *map++;
                }
            }
        }
        count++;
    }

    free(map - 484);
    printf("line 29\n");
    fclose(maps);
}
