#include <ansi.h>
inherit NPC;
mapping exit=([ ]); 
string where ="";

mapping areas= ([
        "/open/world1/acme/area/" : "�ѫ�",
        "/open/world1/moonhide/area/" : "�Ѭ�",
        "/open/world1/tmr/area/" : "�ɿ�",
        "/open/world1/wilfred/meadow/" : "�������",
        "/open/world1/wu_sha_town/" : "�L�F��", 
        "/open/world1/cominging/area/" : "�B�F��",]);

int restart();
string eq_check();
void create()
{
        set_name(HIY"�~�~"NOR, ({ "year monster","monster"}) );
        set("long","�@���D�`�j�������~�A�b�L�~�ɤ~�|�ӳo�̡C\n");
        set("title",HIG"�s�~�ּ�"NOR);
        set("level",30);
        set("race","���~");
        set("age",777);
        set("no_fight", 1);
        set("monster-beard",1);
        set("chat_chance", 10);
        set("chat_msg", ({
//                (: return_home(load_object("/open/world1/cominging/area/boo-lin")) :),
                "�~�~�µۤѪŤ������ۥs�u�q~�v�I\n", }) 
        );
        setup();
             set_living_name("monster-beard");
}
void init()
{
        object me,obj;
        ::init();
        me=this_player();
        if(objectp(obj=present("cracker",me) ) )
        {
          call_out("flee",2);
        }
}
int flee()
{
        int i;
        object me,obj,env;
        string to_dir,to_dir_name,*dir,*dir_name;
        obj=this_object();
        me=this_player();

        env = environment(me);
        exit = env->query("exits");
        dir_name = keys(exit);
        dir = values(exit);

        i = random(sizeof(dir));
        to_dir = dir[i];
        to_dir_name = dir_name[i];
        obj->move(to_dir);
        message_vision("$n�o�{$N���۬��⪺�F��A�Q���n�_�C\n",me,obj);
        write( obj->query("name")+"��"+to_dir_name+"�w�C�����L�h�F�C\n");
        return 1;
}

