inherit ROOM;

void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
���ùȿڣ�ֻ��һƬ��ݵ��ϰ����߰��ŷ��������˶���
��һϯ�⣬ÿ�����Զ��������ˡ��������Ÿ��ɵ����š�����
���������ˡ�
LONG);
        set("exits", ([
                "west":__DIR__"daobian",
                "east":__DIR__"huichang",
        ]));
        setup();
}