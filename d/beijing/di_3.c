#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����Ǳ����ǵذ��ŵ����֡��ֵ�����������������֣������������ﲻ
����������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ���
�������Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣴�����һֱ��
�����Ե��ﵱ����һ�����ݵĸ�ۡ�����Ͼ�����������ֿ���ͨ����������
���������ֵĵذ������ֹ㳡��
LONG );
       set("exits", ([
		"north" : __DIR__"di_4",
		"south" : __DIR__"di_1",
		"east" : __DIR__"di_xigc",
	]));
	set("objects", ([
		__DIR__"npc/tiaofu" : 1,
		__DIR__"npc/dipi" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
