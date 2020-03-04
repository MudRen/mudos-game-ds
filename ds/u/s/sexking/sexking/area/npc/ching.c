#include <ansi.h>
inherit NPC;
void create()
{
             set_name(HIG"�L���ݤ]", ({ "ching gin"NOR,"gin","ching"NOR}) );
             set("level",30);
             set("combat_exp",5000);
             set("long" ,"�L�O�@��I�d�ݺާ߮���H��J�f������..�����@�I�ܥ������ˤl�C\n"
                         "�L�Q�����L�q�ܱj���H���]�Q�������S�Ϊ��H..�p�G�A�{���A�O�j�̪���\n"
                         "�i�H"HIR"�z�o(burst)"NOR"�ۤv���p��"HIC"�\\�O"NOR"���L�ݬݡC\n");
             set("age",39);
             set("gender","�k��");
             set_skill("blade",90);
             set_skill("dodge",90);
             set_skill("parry",50);
             set_skill("combat",100);
             set("talk_reply","�Ф��n���Z��..�ڱo�M�ߪ��ɩ�¾�u�C");
             set("chat_chance",8);
             set("chat_msg", ({
  name()+"�b�}��������:�Q�L�h?��ڤU��(Kneel)�a.....�C\n",
  name()+"�M�ߪ��M�U�|�P�����R�A�@��@��]����L�C\n"NOR,
  (: command("think") :),
  }) );
setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
       }
void init()
{
       object me;
       ::init();
       if(interactive(me = this_player()) && !is_fighting()) 
       {
       remove_call_out("man");
       call_out("man",1,me);
       }
       add_action("do_guard", "go");
       add_action("do_knee","Kneel");
       add_action("do_burst","burst");
}
int do_guard(string arg)
{
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        {
        if(this_player()->query_temp("nice")>=1)
        { 
        message_vision(HIM"�L���ݤ]�����q�q����:�o��Э^���ФF...�C\n"NOR,this_player());
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        } 
        if(this_player()->query_temp("bad")>=1)
        {
        message_vision(HIM"�L���ݤ]���ۻ�:�p��J���C�I�O�L�ۤF...�C\n"NOR,this_player());
        command("hoho");
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        }
         else
        {
        write( name() + "�N�A�פF�U�ӡC\n");
        command("no");
        say("�L���ݤ]���D�G"HIR"�o�̤��O�A�ӨӪ��a��I�I\n"NOR);
        return 1;
  }
}
}
int do_knee(string arg)
{
     if(arg!="gin")
     {
                notify_fail("�Х�Kneel (�H�W)\n");
                return 0;
     }
     if(this_player()->query_temp("nice")>=1)
     {
     message_vision(HIG"�L���ݤ]��������:������.������.�а_�а_!\n"NOR,this_player());
     return 1;
     }
     else
     {     
     message_vision(HIG"$N��۲L���ݤ]�����q�q�����F�U�h..�C\n"NOR,this_player());
     call_out("kneel1",3,this_player());
     return 1;        
     }
}
void kneel1(object me)
{
     if(!me) return;
     message_vision(HIC"�L���ݤ]�ﯺ�ۻ�:������!�A�u���O�Ө�J��..�L�h�a..�C\n"NOR,me);
     me->move("/u/s/sexking/sexking/area/map_2");
     me->set_temp("bad",1);
     tell_room(environment(me),me->name()+"��M�^�^�������]�F�i�ӡC\n",({me}));
     return;
}
int do_burst(string arg)
{
        if(arg!="�\\�O")
        {
                notify_fail("�A�n�z�o�\\�O�Х� burst �\\�O\n");
                return 0;
        }
        if(this_player()->query("level") >25)
        {
        message_vision(HIY"$N�z�o�X�ۤv���p�����l�H�Υ\\�O..�ݱo�L���ݤ]�����áC\n"NOR,this_player());
        message_vision(HIC"$N���\\�O�ϲL���ݤ]������ı�o���s�n...�C\n"NOR,this_player());
        this_player()->start_busy(2);
        this_player()->set_temp("nice",1);
        call_out("go",3,this_player());
        return 1;
 } 
        else
        {
        message_vision(HIR"$N�{�X�F�T�}�ߪ��\\�Ҧb�L���ݤ]���e�R�F�@�R�C\n"NOR,this_player());
        message_vision(HIC"�ݱo�L���ݤ]�����j���C\n"NOR,this_player());
        this_player()->start_busy(1);
        call_out("go2",4,this_player());
        return 1;
}
}
void go(object me)
{
     if(!me) return;
     message_vision(HIM"�L���ݤ]��Y����:�z!�A�G�M�O�@�W�^��,�w���w��!.��§�F...�C\n"NOR,me);
     me->move("/u/s/sexking/sexking/area/map_2");
     tell_room(environment(me),me->name()+"��������,�������������F�L�ӡC\n",({me}));
     return;
}
void go2(object me)
{
     if(!me) return;
     message_vision(HIY"�L���ݤ]�ܤ��n����:�A��ڤT���p�ĳ�?�o�ؤT�}�ߪ��\\�Ҥ]���X�Ӳ{��...�C\n"NOR,me);
     return;
}
void man(object me)
{
if(this_player()->query_temp("nice")>=1)
{
message_vision(HIC"�L���ݤ]���q����:�A�O"HIY + me->name(1) + NOR""HIC"�j�L�a..�ڤw�g���ѹL�A����O�F..�жi�жi!\n"NOR,me);
return;
}
if(this_player()->query_temp("bad")>=1)
{
message_vision(HIC"�L���ݤ]���}�}����:�A�N�O"HIY + me->name(1) + NOR""HIC"�p��J��?�N��A�i�h�]�S�H�|�`�N�A���s�b��..\n"NOR,me);
command("hoho");
tell_object(me,HIR"�A��M�@�{�l��..�����D���۰d��ɯ�Q�^�ӡC\n"NOR);
return;
}
}



