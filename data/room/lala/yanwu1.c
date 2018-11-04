// File(/data/room/lala/yanwu1.c) of lala's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "奈落演武厅");
	set ("long", @LONG
这是奈落的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
LONG );

	set("exits", ([
                "west" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "无悔");
        set("room_name", "奈落");
        set("room_id", "lai");
        set("room_owner_id", "lala");
        set("room_position", "山路");
}
