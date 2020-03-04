#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�ʯ��Ų", ({ "medicine book","book" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@������Ǫ̾ǲ�(read)���Ĩ�.");
                }
        setup();
}

void init()
{
        add_action("do_read","read");
}

int do_read(string arg)
{
      object me,obj;
      me=this_player();
      obj=this_object();
      obj->set_temp("read_book",1);
      if (arg != "book") return 0; 
      if(me->query_skill("literate") > 20)
                return notify_fail(CYN"�A�w�g�i�H�x���o���Ѫ����e�F�C\n"NOR);
      if(me->is_fighting() )
                return notify_fail(CYN"�b�԰���Ū��?!..\n"NOR);
      if( sizeof(me->query_temp("is_busy")) )
		 return notify_fail(CYN"�A�{�b���b���A�L�kŪ�ѣ�..�C\n"NOR);
      if(me->query_skill("literate") == 0)
                return notify_fail(CYN"�A�٬O�媼�C...-_-..�C\n"NOR);
      message_vision("$N�ݤF�ݤ⤤�ʯ��Ų...\n"  ,me);
      obj->set_temp("read_book",1);
      call_out("read_book",1,obj);
 return 1;
}
void read_book()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("read_book");
      switch( i ) {
          case 1:
            message_vision(CYN"$N�P�P��a, �N�a���UŪ�_�ʯ��Ų..\n"NOR, me);
            obj->set_temp("read_book",i+1);
	    me->receive_damage("mp",10); 
            call_out("read_book",3,me);
	    me->start_busy(2);
            break;
          case 2:
            if(me->query("mp") >= 10 ) 
            {
              message_vision(CYN"$N���E��|����Ū�ۦʯ��Ų..\n"NOR, me);
              me->receive_damage("mp",10); 
	      me->improve_skill("literate",10);
	      me->start_busy(2);
              obj->set_temp("read_book",i+1);
	      call_out("read_book",3,me);
            }
            else
	    {
	      message_vision(HIR"$N�����@���V��, �n�ɯ��F�_��.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
            break;
	  case 3:
            if(me->query("mp") >= 10 ) 
            {
              message_vision(CYN"$N���E��|����Ū�ۦʯ��Ų..\n"NOR, me);
              me->receive_damage("mp",10); 
	      me->improve_skill("literate",10);
	      me->start_busy(2);
              obj->set_temp("read_book",i+1);
	      call_out("read_book",3,me);
            }
            else
	    {
	      message_vision(HIR"$N�����@���V��, �n�ɯ��F�_��.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
             break;
	    case 4:
            if(me->query("mp") >= 10 ) 
            {
              message_vision(CYN"$N���E��|����Ū�ۦʯ��Ų..\n"NOR, me);
              me->receive_damage("mp",10); 
	      me->improve_skill("literate",10);
	      me->start_busy(2);
              obj->set_temp("read_book",i+1);
	      call_out("read_book",3,me);
            }
            else
	    {
	      message_vision(HIR"$N�����@���V��, �n�ɯ��F�_��.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
            break;
            case 5:
            if(me->query("mp") >= 20 ) 
            {
              message_vision(CYN"$N�X�_�ʯ��Ų, �q�Q��~Ū�쪺�s��.\n"NOR, me);
              me->receive_damage("mp",30); 
	      me->improve_skill("literate",20);
	      me->start_busy(2);
              obj->delete_temp("read_book");
	      me->delete_temp("read_book");
            }
            else
	    {
	      message_vision(HIR"$N�����@���V��, �n�ɯ��F�_��.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
            break;
      }
}

