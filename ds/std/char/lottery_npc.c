//�зǺN�m�ӤH�~����    - by Luky -
// V2.0 by Tmr 2007/01/24
// �令�u�|�P�m�v�����k

#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
string args;

void create()
{
    seteuid(getuid());
}

string item_desc(object ob)
{
    if(ob->is_ticket()) return HIC+"�m��"+NOR;
    else if(ob->query("skill_type")) return HIG+"�Z��"+NOR;
    else if(ob->query("armor_type")) return HIY+"����"+NOR;
    else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"�^�_"+NOR;
    else if(ob->is_food()) return HIM"����"NOR; // by shengsan
    else return "�D��";
}

string item_list(object ob)
{
    return sprintf("%8d .............. %4s  %-26s",
                   ob->query("value"),item_desc(ob),ob->short()
                  );
}

int do_list(string arg)
{
    object goods,me;
    mapping item;
    string list, *file;
    int i,*supply_cost,debug;

    me=this_player();

    if(wizardp(me) && me->query("env/debug")) debug=1;
    else debug=0;

    if(!mapp(item = query("sell_list")) )
    {
        write("�o������ӤH�S�����~�C��I\n");
        return 0;
    }
    file =  keys(item);
    supply_cost = values(item);
    list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
    list +="�x �� ��                ����  �ثe�i�H�ʶR���f�~�M��    �x\n";
    list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
    for(i=0; i<sizeof(file); i++)
    {
        goods = load_object(file[i]);
        if(goods)
        {
            list+= item_list(goods);
            if(goods->is_ticket() && !LOTTERY_D->can_buy_ticket()) list+= "<�w�⧹>";
            if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
            else list+="\n";
        }
    }
    list +="\n";
    if(i==0) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�f���槹�F�C\n");
    else me->start_more(list);
    return 1;
}

int do_buy(string arg)
{
     int amount,valus,i,j,*supply_cost,world;
    object goods,ob,me;
    string item,*file;
    mapping items;

    me = this_player();
    if(!arg) return notify_fail("�A�n�R����F��H\n");

    if(sscanf(arg,"%d %s",amount,item)!=2)
    {
        amount=1;
        item = arg;
        if(item == "ticket")
        {
            // ���o�@�ӥ|�P�m
            amount = LOTTERY_D->find_ticket_num();
        }
    }

    if(!mapp(items = query("sell_list")) )
    {
        write("�o��p�c�S�����~�C��I\n");
        return 0;
    }


    file =  keys(items);
    supply_cost = values(items);
    for(i=0; i<sizeof(file); i++)
    {
        goods = load_object(file[i]);
        if(goods)
        {
            if(goods->id(item))
            {
                if(goods->is_ticket())
                {
                    if(!me->can_afford(goods->query("value")))
                        return notify_fail("�A���W���������C\n");
                    if( (goods->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )
                        return notify_fail("�A�����ʳo��h�F��C\n");
                    if( (int)me->query_capacity() + (int)goods->query("volume") > (int)me->query_max_capacity() )
                        return notify_fail("�A���W�񤣤U�o��h�F��C\n");
                    if( me->query("supply_point") < supply_cost[i])
                        return notify_fail(this_object()->query("name")+"��A��: �A�w�g�R�F���֪F��F..�٬O���L�@�|��A�ӶR�a.. �C\n");
                    if( amount < 0 || amount > LOTTERY_D->query_max_ticket() ) return notify_fail("�S���o�Ӹ��X��C\n");
                    //                    if(!LOTTERY_D->can_buy_ticket()) return notify_fail("�����m���w�g�����槹�F�C\n");
                    //                  if(!LOTTERY_D->add_ticket_number(amount)) return notify_fail((string)amount+"�����m���w�g�汼�F�C\n");

                    valus=goods->query("value");
                    me->receive_money(-valus);
                    me->add("supply_point",-supply_cost[i]);
                    message_vision("$N��F"+price_string(valus,me->money_type())+"�V$n�R�F�@�i"+
                                   amount+"����"+goods->name()+"�C\n",me,this_object());
                    ob = LOTTERY_D->createTicket();
                    ob->set("number",amount);
                    if(me->query_encumbrance() + ob->weight() > (int)me->query_max_encumbrance()) ob->move(environment(me));
                    else ob->move(me);

                    me->save();
                    return 1;
                }
                else
                {

                    if(!me->can_afford(goods->query("value")*amount))
                        return notify_fail("�A���W���������C\n");
                    if( (goods->query_weight()*amount+me->query_encumbrance())>me->query_max_encumbrance() )
                        return notify_fail("�A�����ʳo��h�F��C\n");
                    if( me->query("supply_point") < supply_cost[i]*amount)
                        return notify_fail(this_object()->query("name")+"��A��: �A�w�g�R�F���֪F��F..�٬O���L�@�|��A�ӶR�a.. �C\n");
                    if( amount < 1 ) return notify_fail("�ܤ֭n�R�@�ӧa�C\n");
                    valus=goods->query("value")*amount;
                    me->receive_money(-valus);
                    me->add("supply_point",-supply_cost[i]*amount);
                    world = me->money_type();
                    message_vision("$N��F"+price_string(valus,me->money_type())+"�V$n�R�F"+
                                   chinese_number(amount)+goods->query("unit")+goods->name()+"�C\n",me,this_object());

                    for(j=0;j<amount;j++)
                    {
                        ob = new(file[i]);
                        if(ob->is_character()) ob->move(environment(me));
                        else    ob->move(me);
                        me->save();
                    }
                    return 1;
                }
            }
        }
    }

    return notify_fail(this_object()->query("name")+"�S����o�تF��C\n");

}

int do_reward(string arg)
{
    string msg;
    object *ticket,me,gift;
    int i,k=0,exp,flag,check, na,nb;
    int pop;

      string where,str="";
    me = this_player();
    ticket=all_inventory(me);
    if(sizeof(ticket)<1)
        return notify_fail("�A�èS���m���i�H����C\n");
    //  if(sizeof(ticket)>50)
    //        return notify_fail("�A���W���m���j��50�i�A�д�֤@�ǦA�ӧI���C\n");

    switch(me->money_type())
    {
    case 1: where="bank/past"; break;
    case 2: where="bank/now"; break;
    case 3: where="bank/future"; break;
    default: where="bank/past"; break;
    }

    flag = 0;
    for(i=0;i<sizeof(ticket);i++)
    {
         if(!ticket[i]->is_ticket() ) continue;
        k++;
        if(k==1) {
            //          str+="$N���F�@�Ǳm����$n�C\n$n�Ӥߦa�@�i�i½�ݵۡC\n";
            message_vision("$N���F�@�Ǳm����$n�C\n$n�Ӥߦa�@�i�i½�ݵۡC\n", me, this_object());
        }
        check = LOTTERY_D->query_lottery(ticket[i]->query("number"),ticket[i]->query("time"));

        switch(check)
        {
        case -2:
            //        str+=YEL"$n�n�n�Y��: �o�i�m���{�b���i�H�����C\n"NOR;
            message_vision(YEL"$n�n�n�Y��: �o�i�m���{�b���i�H�����C\n"NOR, me, this_object());
            break;
        case -1:
            //message_vision(YEL"$N�n�n�Y��: �o�i�m���w�g�L���F��C\n"NOR"$N�ΤO��m���������F�C\n",this_object());
            destruct(ticket[i]);
            break;
        case 0:
            //message_vision(YEL"$N�n�n�Y��: �o�i�m���èS������, �Ʊ�A�U�����B��|����n�C\n"NOR"$N�ΤO��m���������F�C\n",this_object());
            destruct(ticket[i]);
            break;
        case 99:
            flag++;
            message_vision(YEL"$n�~�F�@��, �_�_���򪺻�:"HIC"�ѭ����  $N...�z���F..�W...�W�Ťj���I�I \n"NOR, me, this_object());
             msg =  sprintf(HIC"�i�m�����ߡj���B��%s(%s)���F��%d��"HIY"�W�Ťj��"HIC"�A�����s��:%4d�C[%8s]\n",me->name(1), me->query("id"), ticket[i]->query("time"),ticket[i]->query("number"), ctime(time())) ;
            message("system", msg ,users());
            RECORD_D->add_temp_record(msg);
            destruct(ticket[i]);
            gift = new("/open/lottery/ankle.c");
            str += "�A�o����~: "+gift->short(1)+"�C\n";
            if(!gift->can_move(me)) gift->move(environment(me));
            else gift->move(me);
            break;
        default:
            // �XA�Xb
            na = check / 10;
            nb = check % 10;
            if(na==0 && nb==0) {
                destruct(ticket[i]);
                break;
            }
            flag++;
            if(na + nb == 4) {
                  msg = sprintf(HIC+"�i�m�����ߡj����%s(%s)���B�����F��%d����"HIG"%2d"HIC"A"HIW"%2d"HIC"B���A�����s��:%d�C[%s]�C\n"NOR,me->name(1), me->query("id"),LOTTERY_D->query_times(),na,nb,ticket[i]->query("number"),ctime(time()));
                message("system", msg ,users());
                RECORD_D->add_temp_record( msg );
            }

            exp = 0;
            if(nb==1) exp = 100;
            if(nb==2) exp = 1000;
            if(nb==3) exp = 20000;
            // 2a2b
            if(na==2 && nb==2) {
                  gift = new("/open/lottery/ankle2.c");
                str += "�A�o����~: "+gift->short(1)+"�C\n";
                if(!gift->can_move(me)) gift->move(environment(me));
                else gift->move(me);
            }


            if(nb==4) {
                gift = new("/open/always/doll2.c");
                str += "�A�o����~: "+gift->short(1)+"�C\n";
                if(!gift->can_move(me)) gift->move(environment(me));
                else gift->move(me);
            }
            pop = 0; // �n��
        if(na==1) { exp += 500;}
            if(na==2) { exp += 10000; pop = 2;}
            if(na==3) { exp += 40000; pop = 4;}
            if(na==4) {
                gift = new("/open/always/doll.c");
                str += "�A�o����~: "+gift->short(1)+"�C\n";
                if(!gift->can_move(me)) gift->move(environment(me));
                else gift->move(me);
            }

            // 1a3b
            if(na==1 && nb==3) {
                exp += 80000;
                pop += 8;
            }

            if(exp>0) {
                me->add("exp",exp);
                str+="�A�o��F"+(string)exp+"�I�g��ȡC\n";
            }
            if(pop>0) {
                me->add("popularity",pop);
                str+="�A�o��F"+(string)pop+"�I�n��C\n";
            }

            destruct(ticket[i]);
        }
    }
    if(k<1)     return notify_fail("�A�èS���m���i�H����C\n");

    tell_object(me, str );
    if(!flag)
    {
        message_vision("$n���$N���ӻH��: �ܥi��, �o�Ǽ������S�����j��, �Ʊ�A�U���B��|�n�@�I�C\n", me, this_object());
        return 1;
    }
    message_vision("$n���L�S���������B�z������, �������M$N���⯬�P�C\n", me, this_object());
    return 1;
}


int is_lottery_npc()
{
    return 1;
}

