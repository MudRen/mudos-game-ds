inherit ITEM;
int do_change(string arg);

void create()
{
    seteuid(getuid());
        set_name("臨時幫會信物更換機", ({ "machine" }) );
        set_weight(100);
        set("unit", "個" );
        set("long", @LONG
change <id>
LONG
        );
}

void init()
{
        if( wizardp(environment()) ) {
                seteuid(getuid(environment()));
                add_action("do_change", "change");
        }
}

int do_change(string arg)
{
	object ob,ob2,me;
	me=this_player();
    if(!arg) return notify_fail("change <人名>\n");
        else
        {
        ob = present(arg, environment(me));
        ob2 = present("ring of heaven and earth", ob);
	    if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
        if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
        if(ob2) destruct(ob2);
        new("/open/always/sky_mark")->move(ob);
        write("OK");
        }
    return 1;
}