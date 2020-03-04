#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short",HIR"�~��");
        set("long",@LONG
�A�@�i��o�̡A�@�ѿ@�@����{���ߧY���F�L�ӡA�䤤�ٲV���۳��~
������C�A��Mı�o�G���@�}½�u�A���T�åX�@�ǭG�ġC�ݨӳo�Ӧa��A
�٬O���n�ݤӤ[����n�C
LONG
        );


         set("exits", ([
       "up":__DIR__"hole_1",
         ]));
        create_door("up","�۪�","down",DOOR_CLOSED);

        set("objects",([
              __DIR__"npc/golden-monkey" : 1,
          ]) );
        setup();

 }
void init()
{
        add_action("do_kick", "kick");
        add_action("do_search", "search");
}
int do_search(string arg)
{
     object me;
     me=this_player();
     if(arg!="�g��")  return 0;
      tell_object(me, HIY "�g���P���F�@���A�A���G�ݨ�g����������ӳq�D�C\n\n" NOR );
      tell_object(me, HIY "�A�θ}��F�@�U�A��A���G���I�P�ʡA�A�ΤO���ݦn�F�C\n\n" NOR );
     return 1;
}
     
int do_kick(string arg)
{
         int t;
        object me;
        me=this_player();
        if(arg != "�g��") return 0;
      if(me->query_str()<10) return notify_fail("�A�ΤO��F�@�}�A�u��T�n�h�T�C\n");
        message_vision( HIG "$N�ΤO��}��n���g���A�g���U���M���@���K�D�T$N�ݨ�K�D��N�p�F�i�h�C\n\n" NOR ,me);
        me->start_busy(3);
        call_out("domessage",3,me,4);

        message_vision( HIG "$N���F�i�h����A��M�@�}�n�ʡT�Y���F�@�Ǥg�ۤS��}�f�I��F�C\n\n" NOR ,me);
      me->move(__DIR__"hole_3");
        return 1;
}
int domessage(object me,int b)
{
 if(b==3) 
        tell_object(me, HIB "�A�^�h�����Q�g�۰���F�A�ݨӥu�n�~�򩹫e����F�C\n\n" NOR );
  else if(b==2) 
        tell_object(me, HIB "�U�p���}���A���o���Ϊ����A��d�g�����D���Aı�o�ۤv�����L�C�C\n\n" NOR );
  else  if(b==1)
      tell_object(me,HIB "�Aı�o�}��M�ܼe�F�A�i�H�s�۸y���ۡC\n\n" NOR );
 else if(b==0)
        {
        tell_object(me,HIY "���Y�O�@���ܮz������A�A��ӫ��եΤO������}�T\n\n" NOR );
        this_object()->delete("user");
        me->move(__DIR__"secret");
       tell_room(environment(me),HIY"�����M�Y��"+me->query("name")+HIY"�q�Y����������p�F�X�ӡC\n"NOR,me);
        return 1;
        }
b--;
me->start_busy(3);
call_out("domessage",3,me,b);
}

