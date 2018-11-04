#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIR "AK47" NOR, ({ "ak47" }));
        set_weight(5000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", HIR "杀人工具，用于瞬间杀人。\n" NOR);
                set("value", 25000);
        }
        init_hammer(30);
        setup();
}
