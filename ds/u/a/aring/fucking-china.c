#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"[2006]"HIR"�y���@��Q�ڭ̱O�����������]"NOR,({ "fucking china red packet","packet" }) );
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long",HIW"
�F�A�Q�@��
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

        switch(random(100))
        { 
                case 1..100:
                        me->add("bank/past", 50000000);
                        message_vision(HIC"$N���}�F"HIR"���]"HIC"��A�̭��~�M�� 50000000  �������I\n"NOR,me,obj);
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

