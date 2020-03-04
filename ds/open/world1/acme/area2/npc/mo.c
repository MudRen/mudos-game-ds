#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "莫無通" , ({ "mo wu tung","tung", "__GUARD__" }) );
        set("level",25);
        set("gender","無性");
        set("combat_exp",2500);
set("exp",1000);
        set("evil",80);
        set("long","他善於偽裝成各種人的樣子。\n");
        set("age",30);
        set("attitude","killer");
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set("Merits/wit",2);
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && this_object()->visible(this_player()))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
          object me;
          string mobname,mobtitle,mobclass,mobnick;
          me=this_player();
          mobname=me->query("name");
          mobclass=me->query("class1");
          mobtitle=me->query("title");
          mobnick=me->query("nickname");
          if( !ob || environment(ob) != environment() ) return;
          {
            command("hehe");
               message_vision("莫無通的臉扭曲變形，慢慢的幻化成$N的樣子。\n",me);
            this_object()->set("name", mobname );
            this_object()->set_temp("apply/id",({me->query("id")}));
            if(me->query("long")) this_object()->set("long",me->query("long"));
            else this_object()->delete("long");
            this_object()->set("title",mobtitle);
            this_object()->set("class",mobclass);
            this_object()->set("nickname",mobnick);
          }
}
