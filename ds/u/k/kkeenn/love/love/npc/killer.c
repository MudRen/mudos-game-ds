#include <ansi.h>
inherit NPC;
void create()
{
        set_name(WHT"�¦�k�l"NOR,({"black killer","killer"}));
        set("long" ,
"�����������K����A�ݦo�D�X�����k�A�i�o���o�Z�\\�]���z�C\n");
        set("nickname", MAG"�_���C��"NOR );
        set("attitude", "friendly"); 
        set("age", 16);
        set("gender","�k��");
        set("level", 22);
        set("class1","������");
        set("title",HIR"���������K����"NOR);
        set_temp("apply/armor",20);
        set_skill("run_cloud",90);
        set_skill("masen_whip",60);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        setup();
        carry_object(__DIR__"obj/whip7")->wield();
        }
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
      }
}
int do_guard(string arg)
{
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
      command("grin");
           say(WHT"�¦�k�l"NOR"�ܹD�G"HIR"�n�����H���ݰݧڪ��@�a�I\n"NOR);
        return 1;
}

