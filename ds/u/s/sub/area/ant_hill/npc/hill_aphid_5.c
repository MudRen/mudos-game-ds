inherit NPC;
void create()
{
        set_name("�H��", ({ "aphid" }) );
        set("race", "beast");
        set("age", 1);
        set("level",5);
        set("long", @LONG
�@���L�p���H�ΡA�b�a�W���Ӫ��h�A�e�������ٶǨӭ��������D�C
LONG);
        set("max_hp",10);
        set("unit","��");
        set("limbs", ({ "�Y��", "����" }) );
        set("verbs", ({ "bite","crash" }) );
        setup();
}

void die()
{
        object meat;
                meat=new_ob(__DIR__"obj/aphid_liquid");
                meat->move(this_object());
        ::die();
}
