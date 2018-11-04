// huoshan ��ɽ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "��ʦ"
#define OPINION_TYPE    HIY "�ڼҹ���" NOR 
#define MY_OPINION      "force"

string  *my_opinions = ({ "force" });

// ��ͷ�ļ�����������Ƕ��
#include <ultra.h>

void create()
{
        set_name("��ɽ", ({ "huo shan", "huo", "shan" }) );
        set("title", HIW "����ʦ" NOR);
        set("gender", "����");
        set("age", 91);
        set("long", "��������װ�������òƽƽ������һ���������ʿ��\n");
        set("attitude", "peaceful");
        set("class", "fighter");
        set("str", 30);
        set("int", 37);
        set("con", 39);
        set("dex", 33);

        set("max_qi", 20000);
        set("max_jing", 20000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 100);

        set("combat_exp", 50000000);

        set("inquiry", ([
                "Ǭ����Ų��" : "�٣��ⶫ������������ʱ�������㲻��ʲô��",
                "����"     : (: ask_opinion :),
                "opinion"  : (: ask_opinion :),
                "��ѧ����" : "�ú�����Լ�����ѧ����(martial-cognize)����ʱ��ʲô�书����С���ƣ�",
        ]));

        set_skill("unarmed", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("sword", 500);
        set_skill("jiuyang-shengong", 500);
        set_skill("qiankun-danuoyi", 500);
        set_skill("martial-cognize", 500);
        set_skill("literate", 220);

        map_skill("parry", "qiankun-danuoyi");
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "qiankun-danuoyi");
        map_skill("unarmed", "jiuyang-shengong");
        map_skill("sword", "jiuyang-shengong");

        prepare_skill("unarmed", "jiuyang-shengong");

        set("opinion/ultra",  1);
        set("opinion/master", 1);

        set("rank_info/self", "����");

        setup();
        carry_object("/clone/cloth/cloth")->wear();

        set("startroom", "/d/mingjiao/xuantianshi");
        check_clone();
}

void init()
{
        object me;

        if (! interactive(me = this_player()))
                return;

        me->delete_temp("want_opinion");
        if (ultrap(me))
                message_vision(CYN "$N" CYN "üͷһ�壬����һ����\n"
                               NOR, this_object(), me);
}

mixed ask_opinion()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("combat_exp") < 200000)
                return "�ߣ�������书Ҳ�����������ۣ�";

        if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
                return "�����ˣ����ڹ��������Ϊ�Ѿ��Ƶ�������ʦ�ˣ�";

        if (is_fighting(me))
                return "��������ʲô������Ӯ���ң����Լ����Լ����۰ɣ�";

        if (me->is_fighting())
                return "��Ȼ���ɣ����Ҹ������ǡ�";

        if (objectp(ob = query_temp("opinion")))
        {
                if (ob == me)
                {
                        command("say ����ʲô������Ҫ���ҡ�");
                        return 1;
                }

                message_vision(CYN "$N" CYN "��Ϊ��ŭ�Ķ�$n" CYN
                               "������û������æ���𣿡�\n" NOR,
                               this_object(), me);
                return 1;
        }

        switch(me->query_temp("want_opinion/shenni"))
        {
        case 0:
                command("say �ðɣ����ǹ�һ�У�����һ��������");
                break;
        case 1:
                command("say ��׼����û�У����˾����ɡ�");
                break;
        case 2:
                message_vision(CYN "$N" CYN "��ü��$n" CYN
                               "�������ҿ��������ǹ����µġ���\n" NOR,
                               this_object(), me);
                break;
        case 3:
                command("say ����ұ���������죡");
                return 1;
        }

        me->add_temp("want_opinion/shenni", 1);
        return 1;
}

int calc_level(object me, string skill)
{
        int lvl;
        string sp;

        lvl = me->query_skill(skill, 1) / 2;
        sp = me->query_skill_mapped(skill);
        if (! sp) return lvl;

        lvl += me->query_skill(sp, 1);
        if (me->query("max_neili") > 4000) lvl += 20;
        return lvl;
}

void do_congration(object me)
{
        command("chat ���������������ǲ�����");
}

int accept_hit(object me)
{
        command("sneer");
        command("say �����" + RANK_D->query_rude(me) + "���������ҵ������ˣ�");
        kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        object weapon;

        if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
        {
                message_vision(CYN "$N" CYN "��$n" CYN "��������"
                               "�ã���Ҳ������ʦ�����ˣ����ɣ���"
                               "�ǱȻ�һ�£���\n" NOR,
                               this_object(), me);
                return 1;
        }

        if (! me->query_temp("want_opinion/shenni"))
        {
                command("say ���ʲôҪ���Ҷ��֣�");
                return 0;
        }

        command("look " + me->query("id"));

        COMBAT_D->do_attack(this_object(), me, 0);

        if (me->query("qi") <= 0)
        {
                message_vision(CYN "\n$N" CYN "ҡҡͷ��$n" CYN
                               "�����������ڵ��书�����Զ����"
                               "��һ�ж��Ӳ�ס����\n" NOR,
                               this_object(), me);
                return notify_fail("����Ҫ�úõ����������ˡ�\n");
        }

        message_combatd(HIC "$N" HIC "�������������$n" HIC "��"
                        "����ԣ�����ͬʱ������������һ���ֻ��"
                        "����ͷ����������������\n��Ȼ$N" HIC "��"
                        "��һ�����ջع�����û��һ�����ͣ�������"
                        "$n" HIC "��Ϊ�Ȼ��\n" NOR, this_object(),
                        me);
        if (me->query("neili") < 3000)
        {
                message_vision(CYN "\n$N" CYN "ҡҡͷ��$n" CYN
                               "�������ʲ����������㣬�����Ժ�"
                               "�������㽫�����������������ɣ�"
                               "��\n" NOR, this_object(), me);
                return notify_fail("�������ǻ�ȥ����һ�������ɣ�\n");
        }
        me->set("neili", 0);
        

        call_out("check_opinion", 2, me);
        set_temp("opinion", me);
        me->delete_temp("want_opinion");
        message_vision(CYN "\n$N" CYN "һ���ֵ��������ˣ�������"
                       "�롣��\n" NOR, this_object(), me);
        return notify_fail("���������ļ������õ�һ�����\n");
}

int accept_kill(object me)
{
        if (me->query("combat_exp") < 500000)
        {
                message_vision(CYN "$N" CYN "��ŭ����������С����"
                               "ʲô�ң����ҹ�����˵��һ�ư�$n" CYN
                               "�����ڵء�\n" NOR, this_object(), me);
                me->unconcious();
                return -1;
        }
        command("sigh");
        command("say �ܺã����껹��û������ʲô�Һ��ҽ����ĸ��֣�");
        return 1;
}

void unconcious()
{
        message("vision", "\n"HIR + name() + "��ɫһ�䣬����һ����"
                "Ѫ������һ�������Ų�����\n\n" NOR, environment());
        command("chat �գ��գ��գ�����ȥҲ��");
        destruct(this_object());
}

void die()
{
        message("vision", "\n"HIR + name() + "���һ����������һ����"
                "Ѫ������һ�����ʹ˲�����\n\n" NOR, environment());
        command("chat ����ȥҲ��");
        destruct(this_object());
}