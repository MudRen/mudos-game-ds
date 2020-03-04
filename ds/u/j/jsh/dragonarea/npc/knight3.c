#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"�s�Ԥh"NOR, ({ "dragon knight","knight","dragon" }) );
        set("level", 35); 
        set("title",HIW"�F"HIY"�s"HIC"�u�� III"NOR);  
        set("race","�H��");
        set("gender","�k��");
        set("age",430);
        set_skill("parry", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70); 
        add("addition_armor",210);
        add("addition_damage",190);  
        set("long","���O�Y�s���T�a���u�áA�O�@�۶ǻ������_���C\n");      
        setup(); 
        carry_object(__DIR__"obj/sword")->wield();
}
void init()
{
        object ob;
        ::init();
        add_action("do_guard", "go");
        if(!this_object()->visible(this_player())) return;
        call_out("greeting", 1, ob);
}
int do_guard(string arg)
{
       if( (arg!= "east") || !this_player()->visible(this_object()) ) return 0;
       write( name() + "�i�}���u�N�A�פF�U�ӡC\n");
       command("peer");
       command("say �Q�L���� . . . ���L�F�ڳo���a !");
       return 1;
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        } 
      message_vision( "$N"+HIG"���e��X�̫�@�ѯu��ǦV�F��A�é��F��j��"+HIW":�ڧ�ڳ̫᪺�O�q���A�A�d�U�n�u�n ! . . "NOR ,this_object() ); 
        ::die();
        return;
}

