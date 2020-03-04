#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("百草圖鑑", ({ "medicine book","book" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本給初學者學習(read)的藥典.");
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
                return notify_fail(CYN"你已經可以掌握這本書的內容了。\n"NOR);
      if(me->is_fighting() )
                return notify_fail(CYN"在戰鬥中讀書?!..\n"NOR);
      if( sizeof(me->query_temp("is_busy")) )
		 return notify_fail(CYN"你現在正在忙，無法讀書ㄛ..。\n"NOR);
      if(me->query_skill("literate") == 0)
                return notify_fail(CYN"你還是文盲耶...-_-..。\n"NOR);
      message_vision("$N看了看手中百草圖鑑...\n"  ,me);
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
            message_vision(CYN"$N鬆鬆衣帶, 就地坐下讀起百草圖鑑..\n"NOR, me);
            obj->set_temp("read_book",i+1);
	    me->receive_damage("mp",10); 
            call_out("read_book",3,me);
	    me->start_busy(2);
            break;
          case 2:
            if(me->query("mp") >= 10 ) 
            {
              message_vision(CYN"$N正聚精會神的讀著百草圖鑑..\n"NOR, me);
              me->receive_damage("mp",10); 
	      me->improve_skill("literate",10);
	      me->start_busy(2);
              obj->set_temp("read_book",i+1);
	      call_out("read_book",3,me);
            }
            else
	    {
	      message_vision(HIR"$N腦中一片混亂, 登時站了起來.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
            break;
	  case 3:
            if(me->query("mp") >= 10 ) 
            {
              message_vision(CYN"$N正聚精會神的讀著百草圖鑑..\n"NOR, me);
              me->receive_damage("mp",10); 
	      me->improve_skill("literate",10);
	      me->start_busy(2);
              obj->set_temp("read_book",i+1);
	      call_out("read_book",3,me);
            }
            else
	    {
	      message_vision(HIR"$N腦中一片混亂, 登時站了起來.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
             break;
	    case 4:
            if(me->query("mp") >= 10 ) 
            {
              message_vision(CYN"$N正聚精會神的讀著百草圖鑑..\n"NOR, me);
              me->receive_damage("mp",10); 
	      me->improve_skill("literate",10);
	      me->start_busy(2);
              obj->set_temp("read_book",i+1);
	      call_out("read_book",3,me);
            }
            else
	    {
	      message_vision(HIR"$N腦中一片混亂, 登時站了起來.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
            break;
            case 5:
            if(me->query("mp") >= 20 ) 
            {
              message_vision(CYN"$N合起百草圖鑑, 默想剛才讀到的新知.\n"NOR, me);
              me->receive_damage("mp",30); 
	      me->improve_skill("literate",20);
	      me->start_busy(2);
              obj->delete_temp("read_book");
	      me->delete_temp("read_book");
            }
            else
	    {
	      message_vision(HIR"$N腦中一片混亂, 登時站了起來.\n"NOR, me);
	      obj->delete_temp("read_book");
	      me->delete_temp("read_book");
	     }
            break;
      }
}

