#include <ansi.h>

inherit NPC;

void create()
{
	set_name("迎宾小姐", ({ "yingbin xiaojie","yingbin" }) );
	set("title",HIW "〖地狱〗杂志社" NOR);
	set("gender", "女性" );
	set("age", 19);
	set("long",
		"这位迎宾小姐正用甜甜的微笑来迎接你的到来。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小姐");
	setup();
        carry_object("clone/cloth/female3-cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
		call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment()) return;
	switch (random(2))
        {
	case 0:
		say("迎宾小姐用甜蜜地声音说道：这位" + RANK_D->query_respect(ob) +
                    "，欢迎来到〖终极地狱〗。\n");
		break;
	case 1:
		say("迎宾小姐向你微微鞠躬，用甜蜜地声音说道：这位" + RANK_D->query_respect(ob) +
                    "，欢迎你去我们网站看看http://www.cnnetgame.com。\n");
		break;
        }
}
