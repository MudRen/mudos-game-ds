//updated by alickyuen on 26/12

inherit NPC;

void create()
{
	set_name("�۹�", ({"stone-statue","statue"}) );
	set("long", "�@�ӥۻs�������H�A�ݰ_�ӫܥ����ˤl.\n");
	set("race","�����H");
	set("age", 24);
	set("level", 25);
set_skill("parry", 100);
set_skill("dodge", 100);
set("attitude", "peaceful");
	setup();
carry_object(__DIR__"eq/garmor.c")->wear();
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
 tell_object(ob,"  ��M�A���ť���v�����B���@���n���C\n");
ob->set_temp("killgoda",1);
        ::die();
        //destruct(this_object());
        return;
}
