// wineskin.c  �s�U

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���ְs�U", ({"jiudai", "wineskin", "skin"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӥΨӸ˦̰s���j�s�U�A�j���˱o�K�B�E�ɪ��s�C\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "�̰s",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}
