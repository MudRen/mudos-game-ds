#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"狐穴"NOR);

 set("long",@LONG 
經過重重危險，屠殺了許多妖狐，終於來到狐穴最深處。你
正緩慢的走入黑暗的洞穴當中，越深入洞中，恐懼越深入你的內
心。忽然間你發現到有一個人影，走近一看竟然是一個可愛的小
女孩，心中不禁起了疑問，為什麼她會這恐怖的狐穴裡.....
LONG);
 
 set("no_clean_up", 0);
 setup();
}           

int valid_leave(object me, string dir)
{
   me = this_player();

  
     if (present("spider",environment(me)) && ( (dir=="north") ) )
       {
        tell_object(me,"不把這個傢伙解決，你那也沒法去！\n");
       }
    else return ::valid_leave(me,dir);

}

