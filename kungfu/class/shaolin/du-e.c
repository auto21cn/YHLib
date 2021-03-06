inherit NPC;
inherit F_MASTER;

#include "/kungfu/class/shaolin/du.h"

#define HEISUO          "/clone/lonely/heisuo1"
#define JIUHUAN         "/clone/lonely/jiuhuan"

mixed ask_me();

void create()
{
        object ob1, ob2;
	set_name("渡厄", ({ "du e", "du", "e" }));
        set("long", @LONG
这是一个面颊深陷，瘦骨零丁的老僧，只见他
脸色枯黄，如同一段枯木。
LONG);
	set("age", 90);
	set("gender", "男性");
	set("class", "bonze");
	set("attitude", "peaceful");
        set("shen_type", 1);

	set("str", 34);
	set("int", 36);
	set("con", 35);
	set("dex", 33);
	set("max_qi", 8000);
	set("max_jing", 6000);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 300);
	set("combat_exp", 3500000);
        set("score", 500000);

	create_family("少林派", 35, "长老");
	assign_apprentice("弟子", 0);

	set_skill("force", 340);
	set_skill("shaolin-jiuyang", 340);
	set_skill("luohan-fumogong", 320);
	set_skill("shaolin-xinfa", 320);
	set_skill("dodge", 320);
	set_skill("shaolin-shenfa", 320);
	set_skill("whip", 340);
	set_skill("riyue-bian", 340);
	set_skill("parry", 340);
	set_skill("finger", 320);
	set_skill("nianhua-zhi", 320);
	set_skill("strike", 320);
	set_skill("sanhua-zhang", 320);
	set_skill("medical", 280);
	set_skill("shaolin-yishu", 280);
	set_skill("buddhism", 400);
        set_skill("literate", 300);
        set_skill("martial-cognize", 340);

	map_skill("force", "shaolin-jiuyang");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	set("inquiry", ([
		"九环锡杖" : (: ask_me :),
	]));

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);
        set_temp("apply/armor", 300);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.he" :),
                (: perform_action, "whip.shang" :),
        }));

	setup();

        if (clonep())
        {
                ob1 = find_object(HEISUO);
                if (! ob1) ob1 = load_object(HEISUO);
                if (! environment(ob1))
                {
                        ob1->move(this_object());
                        ob1->wield();
                } else
                {
                        ob1 = new("/d/shaolin/obj/changbian");
                        ob1->move(this_object());
                        ob1->wield();
                }

                ob2 = find_object(JIUHUAN);
                if (! ob2) ob2 = load_object(JIUHUAN);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        set_temp("handing", ob2);
                }
        }
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

mixed ask_me()
{
	object ob;
        object me;
        object owner;

        me = this_player();

	if (! me->query_temp("valid_in_fumoquan"))
	{
		command("say 大胆鼠辈，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		kill_ob(me);
                return 1;
	}

        if (me->query_temp("valid_in_fumoquan") != 1)
        {
                command("heng");
                return 1;
        }

        if (me->query("combat_exp") < 1000000)
                return "你这点微末本事，打听达摩祖师留下的利器作甚？";

        ob = find_object(JIUHUAN);
        if (! ob) ob = load_object(JIUHUAN);

        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "东西不已经给你了么？你还打算怎的？";

	if (owner == environment(me))
        {
                command("sneer");
                command("get " + ob->query("id"));
                return "百年来还没人敢愚弄老衲，滚开！";
        }

        if (objectp(owner) && owner != this_object())
		return "此时九环锡杖并不在老衲手中。";

        ob->move(this_object());

        command("buddhi");
        command("give jiuhuan xizhang to " + me->query("id"));
        return 1;
}

int accept_object(object me, object ob)
{
        if (base_name(ob) != HEISUO
           && base_name(ob) != JIUHUAN)
        {
                command("say 你给我这种东西干什么？");
                return 0;
        }

        command("nod");
        command("say 甚好，甚好。");
        destruct(ob);
        return 1;
}
