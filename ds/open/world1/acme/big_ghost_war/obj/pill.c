/* write by -Acme-
*/

inherit ITEM;
inherit F_FOOD;

void create()
{
    switch( random(5) ) {
        case 0:
            set_name("������", ({ "all pill", "pill" }) );
            set("long", "�@���o�۴c�䪺�P���B�e�¦⤧�Ǥ��C\n");
            set("value", random(2000)+1);  
            set("heal_hp", random(500)+1);
            set("heal_ap", random(500)+1);
            set("heal_mp", random(500)+1);
            break;
        case 1:
            set_name("�׮�", ({ "ap pill", "pill" }) );
            set("long", "�@�����Ϊ�����p���ġC\n");
            set("value", random(2000)+1);  
            set("heal_ap", random(500)+1);
            break;
        case 2:
            set_name("������", ({ "mp pill", "pill" }) );
            set("long", "�@�����⪺���ŧe�٪����p���ġC\n");
            set("value", random(2000)+1);  
            set("heal_mp", random(500)+1);
            break;
        default:
            set_name("�E�R��", ({ "hp pill", "pill" }) );
            set("long", "�@���Ŧ⪺�T���Τp���ġC\n");
            set("value", random(2000)+1);  
            set("heal_hp", random(500)+1);
            break;
    }

    set_weight(10);
    set("unit", "��");
    set("food_remaining",1);
    setup();

}
