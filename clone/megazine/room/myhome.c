#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; } 

void create()
{
        set("short",HIG "绿语堂" NOR);
	set("long", @LONG
这里是风狐的“绿语堂”，你可以从这里的建筑风格看出这里的
主人独特的风格。
LONG
	);

	set("exits", ([ 
                        "out" : __DIR__"fiveroom",
        ]));

        set("sleep_room",1);   
	setup();
}
