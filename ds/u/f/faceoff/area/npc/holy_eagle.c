inherit NPC;

void create()
{
        set_name("神鷹",({"holy eagle","holy","eagle"}) );
 set("long","一隻充滿智慧的神鷹, 據說已經半人半精了.它光滑的羽毛使你想摸一摸(touch它.....\n");
        set("age",10);
        set("race","野獸");
        set("level",12);
        set("attitude", "peaceful");
        set("chat_chance",6);
        set("chat_msg",({
        "神鷹百無聊賴的拍了拍翅膀 \n",
        (:command("think"):),            
        "你忽然感到一股凌厲的目光自神鷹眼中射了出來!!\n" ,
        }) );
        set_skill("unarmed",20);
        setup();
}

void init()
{
add_action("do_touch","touch");
}
int do_touch(string arg)
{
      object me;
      object p;
      me=this_player();
     if (arg != "神鷹" && arg !="eagle") return 1;
      message_vision("$N施展出疾如迅雷的手法摸向神鷹的羽毛!\n" ,me);
      if(this_object()->query_temp("feather") > 0)
      {
           message_vision("$N被神鷹的喙狠狠的啄了一下!!\n",me);
      }
      else {
           message_vision("$N從神鷹身上拔下一根羽毛!\n" ,me);
           p=new(__DIR__"obj/feather.c");
           p->move(this_player());
           me->set_temp("meet_eagle",1);
           this_object()->set_temp("feather",1);
           call_out("again",900);
       }                               
      return 1;
}
int again()
{
      message_vision("你聽見神鷹發出一陣陣的鳴叫聲。\n",this_object());
      this_object()->delete_temp("feather");
}
