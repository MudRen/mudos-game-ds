#include <ansi.h>
inherit NPC;
void create()
{
             set_name( "���H����f�u��", ({ "guard","guard" }) );
             set("level",20);
             set("combat_exp",2000);
             set("long" ,"�L�O�C�ѻP�䥦���H���y���Z�u�ê��Z�h�C\n");
             set("age",35);
             set("gender","�k��");
             set_skill("blade",45);
             set_skill("dodge",40);
             set_skill("parry",40);
             set_skill("combat",40);
             set("talk_reply","�ڦb�u�ä��n�n�ڡC");
             set("chat_chance",8);
             set("chat_msg", ({
  name()+"��:��!�p�l�A�n�F��?�C\n",
  name()+"����ۤM�`�A���O�H�ɭn�X�M���ˤl�C\n",
  (: command("hmm") :),
  }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/rattan_leggings")->wear();
}
void init()
{
       object me;
       ::init();
   add_action("do_guard", "go");
}
int do_guard(string arg)
{
if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        {
        if ( this_player()->query_temp("nice")>=1)  
        { 
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        } 
        if ( this_player()->query_temp("bad")>=1)
        { 
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        } 
        else
        {
        write( name() + "�N�A�פF�U�ӡC\n");
        command("no");
        say("���H����f�u�û��D�G"HIR"�o�̤��O�A�ӨӪ��a��I�I\n"NOR);
        return 1;
        }
}
}
