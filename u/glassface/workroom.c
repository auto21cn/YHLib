inherit ROOM;

void create()
{
        set("short", "冥想空间");
        set("long", @LONG
这里是冥想空间。好空旷的地方，一片白茫茫，什么也没有。
LONG );
        set("exits", ([
                "out"  : "/d/wizard/guest_room",
        ]));
        set("valid_startroom", 1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}

