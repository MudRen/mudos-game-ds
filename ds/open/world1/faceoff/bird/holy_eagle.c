inherit NPC;

void create()
{
        set_name("���N",({"holy eagle","holy","eagle"}) );

 set("long","�@���R�����z�����N, �ڻ��w�g�b�H�b��F.�����ƪ��Ф�ϧA�Q�N�@�N��.....\n"
);
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
int k=1;
int do_touch(string arg)
{
      object me;
      object p;
      me=this_player();
      if (arg != "���N") return 1;

       message_vision("$N�I�i�X�e�p���p����k�N�V���N���Ф�!\n" ,me);

    if(k != 0){
           message_vision("$N�q���N���W�ޤU�@�ڦФ�!\n" ,me);
           k = 0;

        p=new(__DIR__"obj/feather.c");
        p->move(this_player());
        me->set_temp("meet_eagle",1);
        } else
        {
                message_vision("$N�Q���N���񬽬����֤F�@�U!!\n",me);
        }                               
        return 1;
}
