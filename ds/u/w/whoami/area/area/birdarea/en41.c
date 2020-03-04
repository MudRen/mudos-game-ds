#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
����o�̡A�A�u���@�}��D���Pı�A���G�O�@�ӳ����ͳJ��
�a��C�|�P���@�ǩ_�Ǫ����Φb�A����L�ۡA���A����ı�o����
����, �Q�����e�̡C�F�_�誺������G�b�o���Z���g�a���z�S�X
�F�޲����T��..
LONG);
  set("item_desc",([
        "����":"�b�e��A�����ݨ����B����i�H�q�L�A���G�O�e���Y�Ӧa�誺�p���C\n",
                  ]));
 set("exits",(["southeast":__DIR__"en40",
               "northwest":__DIR__"en46",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        
void init()
{
  if ( (query_temp("cut_over")) < 1){
   add_action("do_cut","cut");  
   add_action("do_pass","pass"); 
  }
}
int do_pass(string arg)
{
        object me; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n��L����H\n");  
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "����") return 0; 
        if (this_object()->query_temp("cut_over") >= 1) {
        tell_object(me,"\n���Y��I�I�������F�_���աI�I\n");
        } else {        tell_object(me,"\n�o����Ӱ��F�A�A�O�藍�L�h��..(���屼���G�O�L���h��)\n"); 
        }        return 1;
}int do_cut(string arg)
{        
        object me,weapon; 
        me=this_player();
        weapon = me->query_temp("weapon");
            
        if (!arg || arg =="")
        return notify_fail("�A�n�屼����H\n");  
         if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
 
        if(!weapon) 
        return notify_fail("�A�S�˳ƪZ���ڡH\n");

        if(weapon->query("skill_type")!="sword" && weapon->query("skill_type")!="blade" 
        && weapon->query("skill_type")!="axe" && weapon->query("skill_type")!="dagger") 
        return notify_fail("�Q�ٶ}�o�ǪF�襲���n�O�⦳�ۤb���Z��..\n");
        
        if (arg != "����") return 0;
        
        message_vision(HIR"\n$N���R�⤤��"NOR + weapon->name() + HIR"�V�F�_���X�F�@�����ӤF..\n"NOR ,me);
        __DIR__"en41.c"->add("exits", ([ "northeast" :  __DIR__"en42.c"]));
        me->start_busy(2);
        set_temp("cut_over",1);
        set_temp("long", @LONG
����o�̡A�A�u���@�}��D���Pı�A���G�O�@�ӳ����ͳJ��
�a��C�|�P���@�ǩ_�Ǫ����Φb�A����L�ۡA���A����ı�o����
����, �Q�����e�̡C
LONG);
        call_out("rb", 300);
        return 1;
}          
void rb(object tob)
{
        delete_temp("cut_over"); 
set("long",@LONG
����o�̡A�A�u���@�}��D���Pı�A���G�O�@�ӳ����ͳJ��
�a��C�|�P���@�ǩ_�Ǫ����Φb�A����L�ۡA���A����ı�o����
����, �Q�����e�̡C�F�_�誺������G�b�o���Z���g�a���z�S�X
�F�޲����T��..
LONG); 
"/open/world1/whoami/birdarea/en41"->delete("exits/northeast"); 
        return;
}

