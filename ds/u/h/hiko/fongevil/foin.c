#include <ansi.h>
inherit ROOM;
string query_test();
int testing=1;
void create()
{
        set("short","���j�U");
        set("long",@LONG
�A�ש�i���񪺤����F�A�̭����ˤl�M�\�]�����j�ѡA�ݰ_�Ӧ��G
�ܤ[�S�H�ӹL�F�A�]�����A�P��Q���_�S�A�����ݰ_�ӳo�̦��ܱ۫j�j��
���N�𮧡A�Q���O�ʦL�F�F���o���F��A����W���F�@�Ӱ��B�C
LONG);
        
        set("item_desc", ([
        "���B" : "�ʦL�������a�A�L�ⴤ���H�Чְh�h\n",
        ]));
        set("exits", ([
            "leave" : __DIR__"fodoor",
        ]));
        set("no_clean_up", 0);        
        setup();
}

void init()
{
        add_action("do_beat","beat");
        add_action("do_select","select");
        call_out("wel_in",0);
}

int do_select(string arg)
{
         object me,ob;
         me=this_player();
         ob=this_object();
         if(!arg) return notify_fail("�A�Q�擄��?\n");
         if(arg=="fire" && !query("test_fire"))
         {
           message_vision(HIR"$N��ܤF��������A�Ƨ@�@�D���������F\n"NOR,me);        
           me->move(__DIR__"fofire_1");
           testing=2;
           ob->set("test_fire",1);
           return 1;        
          }      
          if(arg=="wind" && !query("test_light"))
         {
           message_vision(HIY"$N��ܤF��������A�Ƨ@�@�D�{�������F\n"NOR,me);        
           me->move(__DIR__"folight_1");
           testing=3;
           ob->set("test_light",1);
           return 1;
         }
         if(arg=="water" && !query("test_water"))
         {
           message_vision(HIB"$N��ܤF��������A�Ƨ@�@�D�ť������F\n"NOR,me);        
           me->move(__DIR__"fowater_1");
           testing=4;
           ob->set("test_water",1);
          return 1;
         }               
         if(arg=="fantasy" && !query("test_fantasy"))
         {
           message_vision(HIM"$N��ܤF�ۤ�����A�Ƨ@�@�D�i�������F\n"NOR,me);        
           me->move(__DIR__"fofantasy_1");
           testing=5;
           ob->set("test_fantasy",1);
           return 1;
         }   
         return notify_fail("���H�b���礤�F��\n");
}        
 
void wel_in()
{        
         object me;
         me=this_player();
         if(testing!=5)
         {
          tell_object(me,"�Ať��F�@���n���J �п��(select)�n�h���Ӹ���\n");
          tell_object(me,HIG"-----"+query_test()+HIG"-----"NOR"\n");          return;
         }
         tell_object(me,"�Ať��@���n���J�A�ӱߤF..�����H�b����F\n");
         tell_object(me,"���h�a�A���ݤU�������|\n");
         me->move(__DIR__"fodoor");
         return;
}

string query_test()
{
         string tesg=""; 
         switch(testing){
          case 1 : tesg+=HIR+"��(fire)"+NOR+",";
          case 2 : tesg+=HIY+"��(light)"+NOR+",";
          case 3 : tesg+=HIB+"��(water)"+NOR+",";
          case 4 : tesg+=HIM+"��(fantasy)"+NOR;
       
       }
       return tesg;
}



