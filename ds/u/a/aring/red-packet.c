#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�C�Ŭ��]"NOR,({ "poor red packet","packet" }) );
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long",HIW"
�ܧC�ŴN�O�F�C
\n"NOR);
        set("unit", "��");
        setup();
}
}
void init()
{
          if(getuid(this_player())=="aring") add_action("do_giveall","giveall");  
          add_action("do_open","open");
}
int do_open(string str)
{
        int amount;
        object obj,me;        
        obj = this_object(); 
        me = this_player();
                
        if(!str || str != "packet")
           return notify_fail("�A�n�}����H\n");
        if(me->query("red-packet2"))
           return notify_fail("�A���w�g�}�L�F�@...\n");

        switch(random(1000))
        { 
                case 0..100:
message("world:world1:vision",HIY"
�i�������]���f�f�j���j�G"HIR+me->query("name")+HIR"���F�̰��S���y�]���ݪ����C�z�I�I\n"NOR,users());                                   new(__DIR__"newyear-face")->move(me);   
                           break;  
                case 101..600:
                        amount = random(50000)+1000000;
                        me->add("bank/past", amount);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A�̭��~�M�� "+amount+" �������I\n"NOR,me,obj);
                        break;
                case 601..800:
                        amount = random(100000)+100000;
                        me->add("exp", random(100000)+1);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A���G��o "+amount+" �I�g��ȡI\n"NOR,me,obj);
                        break;
                case 801..950:
                        amount = random(300)+1000;
                        me->add("popularity", amount);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A���G��o "+amount+" �I�n��I\n"NOR,me,obj);
                        break;
                case 951..1000:
                        new(__DIR__"big-manto")->move(me);//�ȥ��@�N
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"�ɡA���~�|�g�I"HIY"���ߡI"HIC"�̭��O BIG MANTO �I\n"NOR,me,obj);
                        break;
           
            }
  destruct(obj);
  return 1;
} 

int do_giveall(string arg)
{
        int i;
        string *list=({}),*temp=({});
        object *ppl,cake;
        ppl=users();
        if(this_object()->query("gived")) list = this_object()->query("gived");
        for(i=0;i<sizeof(ppl);i++)
        {
                if(getuid(ppl[i])=="jangshow") continue;
                if(!cake=new(base_name(this_object()))) continue;
                if(present("poor red packet",ppl[i])) continue;
                if(sizeof(list))
                {
                        if(member_array(getuid(ppl[i]),list)!=-1) continue;
                }
                
                if(cake->move(ppl[i]))
                {
                                          tell_object(ppl[i],HIW"\n\t�]����M�{���󦹡A�x�F�j�������]�A�M�ӧA�B����@�I�I\n"NOR);
                       temp+=({getuid(ppl[i])});  //����
                       tell_object(ppl[i],HIY"\n\t       �����]�A�]���w�w�����}�C\n"NOR);
                } else tell_object(ppl[i],HIG"\n�]���f�f��M«�X�ӡA�S�n�n�Y�N���F�C\n"NOR);
        }
        write(NOR+CYN"�@�@�e���F"HIW+sizeof(temp)+NOR+CYN"�Ӫ��a���]�C\n"NOR);
        temp+=list;
        this_object()->set("gived",temp); //�x�s����
        return 1;
}

