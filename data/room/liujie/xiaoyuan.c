// File(/data/room/liujie/xiaoyuan.c) of liujie's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "听雨轩小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是青石官道，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of liujie");
	setup();

	set("exits", ([
                "out"    : "/d/suzhou/road1",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "区去");
        set("room_name", "听雨轩");
        set("room_OWNER_ID", "liujie");
        set("room_id", "tingyu");
        set("room_position", "青石官道");
}
