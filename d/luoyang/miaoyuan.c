#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����������������������Ļ��һ���������ң������������滨
��ݺǻ������У���Ȼ�����и������ĵ����ֻ����ĵ����ģ��׵ģ���
�ģ��ϵģ��Ƶģ���ɫ���������涷�ޣ��������Σ������Ͱ�����һ���
Ϊ����������������Ҳ�����������ֻ���
LONG);
        set("outdoors", "luoyang");
        set("no_fight",1);
        set("no_clean_up", 0);
        set("exits", ([
		"west" : __DIR__"miaopu",
	]));

	setup();
}

void init()
{
        add_action("do_jiaoshui", "jiaoshui");
        add_action("do_peiyu", "peiyu");
}

int do_peiyu()
{
        object ob, me;
        me = this_player();

        if (! me->query_temp("zhonghua"))
        {
                tell_object(me, "�����Ӷ�û�У������ֻ���\n"); 
                return 1;
        }

        if (me->query_temp("jiaoshui") == 1)
        {
                tell_object(me, "���Ѿ��������������������ڿ��Խ�ˮ"
                                HIY "(jiaoshui)" NOR "��\n");
                return 1;
        }

        if (me->query("combat_exp") < 8000)
        {
                tell_object(me, "��ľ�����ǳ�������ȵ������߶��߶��ɡ�\n");
                return 1;
        }

        if (me->query("combat_exp") > 30000)
        {
                tell_object(me, "��������ݴ�Ų��ʺ��ֻ��˰ɡ�\n");
                return 1;
        }

        if (me->query("jing") < 70)
        {
                tell_object(me, "���Ѿ���ƣ���ˣ���Ϣһ���ٽ����ְɡ�\n");
                return 1;
        }

        message_vision(HIC "$N" HIC "��������Χ�úõ�������һ�£�ʹ��������"
                       "�ʺϻ���������\n" NOR, me); 
        me->set_temp("peiyu", 1);
        me->set_temp("jiaoshui", 1);
        me->start_busy(1 + random(3));
        return 1;
}

int do_jiaoshui()
{
        object me, ob;
        int exp, pot;

        me = this_player();

        if (me->query("jing") < 70)
        {
                tell_object(me, "���Ѿ���ƣ���ˣ���Ϣһ���ٽ����ְɡ�\n");
                return 1;
        }
        if (me->is_busy())
        {
                tell_object(me, "����æ���أ����ż���\n");
                return 1;
        }
        if (! me->query_temp("peiyu") == 1)
        {
                tell_object(me, "��û�¸ɽ�ʲôˮ����\n");
                return 1;
        }
        if (me->query_temp("peiyu") == 2)
        {
                if (random(14) < 4)
                {
                        switch (random(5))
                        {
                                case 1 : ob = new("/clone/megazine/obj/hmeigui"); break;
                                case 2 : ob = new("/d/changan/npc/obj/zi-luolan"); break;
                                case 3 : ob = new("/d/changan/npc/obj/bai-chahua"); break;
                                case 4 : ob = new("/d/changan/npc/obj/huang-meigui"); break;
                                case 0 : ob = new("/d/changan/npc/obj/lan-tiane"); break;
                        }

                        if (random(15) == 1)
                        {
                                if (random(10000) == 8)
                                {
                                        ob = new("/d/shenlong/obj/hua4");
                                        message_vision(HIY "$N" HIY "�ֳ���һ���������\n"
                                                       NOR, me);
                                        ob->move(me, 1);
                                        me->delete_temp("jiaoshui");
                                        me->delete_temp("zhonghua");
                                        me->delete_temp("peiyu");
                                        me->add("combat_exp", 500);
                                        me->improve_potential(100 + random(100));
                                        return 1;
                                }
                                ob = new("/d/shenlong/obj/hua2");
                                me->add("combat_exp", 20 + random(10));
                                me->improve_potential(20 + random(10));
                                message_vision(HIY "$N" HIY "�ֳ���һ����������\n" NOR,me);
                                return 1;
                        }
                        message_vision(HIC "$N" HIC "ʮ��С�ĵĸ�С���ｽ��һЩ"
                                       "ˮ��ͻȻһ��" + ob->query("name") + HIC
                                       "�ӿ���ð�˳�����\n" NOR, me);   
                        message_vision(HIY "$N" HIY "����ժ���������������\n" NOR, me);
                        ob->move(me, 1);
                        me->delete_temp("jiaoshui");
                        me->delete_temp("peiyu");
                        me->delete_temp("zhonghua");

                        exp = 10 + random(10);
                        pot = 2 + random(3);

		        if (me->query("potential") > me->query_potential_limit()) 
				pot = 1;

                        me->add("combat_exp", exp);
                        me->improve_potential(pot);

                        tell_object(me, HIC "ͨ�����ѵ����������" + chinese_number(exp)
                                        + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n"
                                        NOR);
                        return 1; 
                }
                message_vision(HIR "$N" HIR "���ֱ��ŵ�����ˮ����С���ｽˮ����"
                               "��ˮ����̫��ѻ������ˡ�\n", me); 
                me->delete_temp("jiaoshui"); 
                me->delete_temp("zhonghua"); 
                me->delete_temp("peiyu"); 
                me->add("jing", -50);
                me->add("combat_exp", 3);
                me->improve_potential(2); 
                return 1; 
        }
        if (me->query_temp("jiaoshui") == 1)
        {
                message_vision(HIC "$N" HIC "����ˮ����С�ӽ���һЩˮ��\n" NOR, me); 
                me->add("jing", -70); 
                me->set_temp("peiyu", 2); 
                me->start_busy(1 + random(2)); 
                return 1;
        }
}