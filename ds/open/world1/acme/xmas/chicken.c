#include <ansi.h>
inherit NPC;
mapping exit=([ ]);
void create()
{
        set_name(HIR"����"NOR, ({ "fire chicken","chicken"}) );
        set("long","�@�������Q���j�����j�����A���W����۷�}�P�C\n");
        set("title",HIC"�t�ϧּ�"NOR);
        set("level",3);
        set("race","���~");
        set("age",2);
        set("Merry_Xmas",1);
        set("chat_chance", 6);
        set("chat_msg", ({
                "�����µ����Ū��Ѫťs�D�G�u�B��B��B���v\n", }) 
        );
        setup();
             set_living_name("Merry_Xmas_chicken");
}
void init()
{
	object me,obj;
	::init();
	me=this_player();
        if(objectp(obj=present("net",me) ) )
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
        message_vision("$n�dı$N���W���Ӧ˺��A�o�X�u�B�B�B���v���s�n�C\n",me,obj);
        write( obj->query("name")+"���e��"+to_dir_name+"�]�L�h�F�C\n");
        return 1;
}
