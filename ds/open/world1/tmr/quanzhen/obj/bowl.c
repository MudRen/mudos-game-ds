// bowl.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���J", ({ "wan", "bowl" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�Ӥ��J�A�̭�������O�H��M�O���աC\n");
                set("unit", "��");
                set("value", 0);
                set("max_liquid", 60);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "water",
                "name": "��",
                "remaining": 60,
        ]) );
}
