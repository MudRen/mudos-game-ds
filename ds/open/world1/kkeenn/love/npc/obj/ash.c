inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("���u", ({"ash"}));
        set("unit","��");
        set("value", 0);
        set("no_sac", 1);
        set("long", "�@��¶ª��ǡC\n");
	set("heal", ([
		"hp" : 1,
		"ap" : 1,
		"mp" : 1,
	]));
	set("eat_msg", "$N�Y�U�@����u�C\n");

        setup();
}
