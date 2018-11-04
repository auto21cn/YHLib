
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "卧室");
	set ("long", @LONG
这是主人的卧室，收拾得井井有条。南窗下是一张大床，床边有
一个柜子。推开窗户可以看到下面的花园，还可嗅到阵阵花香，非常
惬意。远处是一大片竹林。
LONG );

        set("exits", ([
                "down" : __DIR__"jusuo",
        ]));

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
        setup();

        set("room_owner", "魔渡众生");
        set("room_name", "血海魔宫");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "山路");
}
