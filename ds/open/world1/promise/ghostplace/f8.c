#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", CYN"�C�s��"NOR);
  set ("long","
�o�N�O���y�F�Ҧb�B�w�u"CYN"�C�s��"NOR"�v�I�I
�b�o���䦳�D"HIY"���ê��}��"NOR"�A�ݦ��H�j�O�������~�}���F�I�I    
�b�����ê��������٦��\\�h"HIB"����"NOR"�b���r�ޡA�Фp�ߡI�I  
\n"NOR);
  set("exits", ([
  "southwest" : __DIR__"f7", 
  ])); 
     set("item_desc",([
     "���ê��}��": HIW"\n�����H���áA�ݭn�e�j���O�q�~����}(push)���C\n"NOR,
        ]));
  set("no_clean_up", 0);
  
  setup();
 } 
void init()
{
        add_action("do_push","push");
}

int do_push(string str)
{

object me;
me=this_player();
     if(this_object()->query_temp("opened") != 0) return 0;
     if(str=="��" || str=="���ê���")      if(me->query("class1") != "�K����") return notify_fail(HIR"�@�óܹD�G����I�o�̤��O�A�o�~�H�i�H�i�J���a��I�H\n"NOR);
        message_vision(
HIC"\n\n�A��ܤ@�n�A��B���x, �ϥX���ޡu�r��w���s�v�A�����a���V���ê����I�I\n\n"HIR"���ê����Q$N"HIR"�����������A���n�ӯ}�I�I
"NOR"(  ���ê��K��"HIR"�l�a�׹F�좰�����H�C "NOR" )\n"NOR,me);
         set("exits",([
        "southwest":__DIR__"f7",
        "enter":__DIR__"w1", 
 ]));
         set("long","           
�o�N�O���y�F�Ҧb�B�w�u�C�s�աv�I�I
�b�o���䦳�D���ê��}���A�ݦ��H�j�O�������~�}���F�I�I    
�b�����ê��������٦��\\�h����b���r�ޡA�Фp�ߡI�I  
"HIR"\n\t\t���H�}���ӤJ�F����
"NOR);            
        set("item_desc",([
        "���ê���":"���ê����w�Q���}�C\n",
        ]));
                  
        set_temp("opened",1); 
                       return 1;
        }
void reset()
{
        set("long","
�o�N�O���y�F�Ҧb�B�w�u"GRN"�C�s��"NOR"�v�I�I
�b�o���䦳�D"HIY"���ê��}��"NOR"�A�ݦ��H�j�O�������~�}���F�I�I    
�b�����ê��������٦��\\�h"HIB"����"NOR"�b���r�ޡA�Фp�ߡI�I  
\n"NOR);
        set("item_desc",([
     "���ê���": HIW"\n�����H���áA�ݭn�e�j���O�q�~����}(push)���C\n"NOR,
       
        ]));

        set("exits", ([
        "southwest":__DIR__"f7.c",
             ]));
        delete_temp("opened");
        ::reset();
}

int room_effect(object me)
{ 
        switch(random(2))

        {
         case 0:
         write(HIR"�b�Ǫ����y�������_���U�N...\n"NOR);
         tell_object(me, HIW"�A�Pı�D�`������..�C\n" NOR ); 
         me->add_busy(2);

         return 1;

         case 1:
         write(HIR"�A�@���`�N�A��D�հ����V�A�Ӽ�.... \n"NOR);
         tell_object(me, HIB "�A����F�@�I�p�N��...�C\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;
        }
}
int valid_leave(object me, string dir)
{
       if( dir=="enter" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
        return ::valid_leave(me, dir);
}

