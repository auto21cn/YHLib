// File(/data/room/wulaoer/jusuo.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
�������ͳǱ��������϶���Ϣ������ĵط���¥�Ͼ������˵�
���ң����������鷿�� 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "���϶�");
        set("room_name", "��ͳǱ�");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "��ʯ�ٵ�");
}