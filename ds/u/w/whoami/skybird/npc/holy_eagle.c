inherit NPC;

void create()
{
        set_name("���N",({"holy eagle","holy","eagle"}) );
 set("long","�@���R�����z�����N, �ڻ��w�g�b�H�b��F.�����ƪ��Ф�ϧA�Q�N�@�N(touch��.....\n");
        set("age",10);
        set("race","���~");
        set("level",12);
        set("attitude", "peaceful");
        set("chat_chance",6);
        set("chat_msg",({
        "���N�ʵL��઺��F��ͻH \n",
        (:command("think"):),            
        "�A���M�P��@�ѭ�F���إ��ۯ��N�����g�F�X��!!\n" ,
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
     if (arg != "���N" && arg !="eagle") return 1;
      message_vision("$N�I�i�X�e�p���p����k�N�V���N���Ф�!\n" ,me);
      if(this_object()->query_temp("feather") > 0)
      {
           message_vision("$N�Q���N���񬽬����֤F�@�U!!\n",me);
      }
      else {
           message_vision("$N�q���N���W�ޤU�@�ڦФ�!\n" ,me);
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
      message_vision("�Ať�����N�o�X�@�}�}����s�n�C\n",this_object());
      this_object()->delete_temp("feather");
}
