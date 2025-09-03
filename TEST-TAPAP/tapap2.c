#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ---------- สินค้า: ชื่อ, ราคา, สต็อกเริ่มต้น (ไม่ใช้ Array/Index) ---------- //
    const char *name1 = "โค้ก";           int price1 = 10; int stock1 = 10; int sale1 = 0; int expired1 = 0; int expDay1 = 30;
    const char *name2 = "น้ำเขียว";        int price2 = 12; int stock2 = 10; int sale2 = 0; int expired2 = 0; int expDay2 = 30;
    const char *name3 = "อเมริกาโน่";      int price3 = 30; int stock3 = 10; int sale3 = 0; int expired3 = 0; int expDay3 = 15;
    const char *name4 = "ลาเต้หวานเจี๊ยบ"; int price4 = 35; int stock4 = 10; int sale4 = 0; int expired4 = 0; int expDay4 = 15;

    const char *name5 = "เมล็ดทานตะวัน";  int price5 = 13; int stock5 = 10; int sale5 = 0; int expired5 = 0; int expDay5 = 15;
    const char *name6 = "ถั่วแปบ";         int price6 = 20; int stock6 = 10; int sale6 = 0; int expired6 = 0; int expDay6 = 7;
    const char *name7 = "จิ้นส้มหมก";      int price7 = 15; int stock7 = 10; int sale7 = 0; int expired7 = 0; int expDay7 = 5;

    // ---------- เงินนในตู้---------- //
    int cnt1000 = 0;  /* แบงก์ 1000 */
    int cnt500  = 2;  /* แบงก์ 500  */
    int cnt100  = 10; /* แบงก์ 100  */
    int cnt50   = 5;  /* แบงก์ 50   */
    int cnt20   = 20; /* แบงก์ 20   */

    int cnt10   = 20; /* เหรียญ 10 */
    int cnt5    = 20; /* เหรียญ 5  */
    int cnt2    = 15; /* เหรียญ 2  */
    int cnt1    = 30; /* เหรียญ 1  */

    // ---------- คำนวณวันใช้งานและเช็กหมดอายุ ---------- //
    int fillDay = 0;

    printf("กรอกวันเติมของ (0-30): ");
    if (scanf("%d", &fillDay) != 1) {
        printf("อินพุตไม่ถูกต้อง\n");
        return 1;
    }
    if (fillDay < 0) fillDay = 0;
    if (fillDay > 30) fillDay = 30;

    srand((unsigned)time(NULL));
    int useDay = (rand() % 30) + 1;  /* วันใช้งานสุ่ม 1..30 */
    printf("วันใช้งาน: %d\n", useDay);

    int usedDays = useDay - fillDay;
    if (usedDays < 0) usedDays = 0;

    /* ถ้าเกินวันหมดอายุให้ตัดสต็อก = 0 และนับหมดอายุ +1 */
    if (stock1 > 0 && usedDays > expDay1) { stock1 = 0; expired1 += 1; }
    if (stock2 > 0 && usedDays > expDay2) { stock2 = 0; expired2 += 1; }
    if (stock3 > 0 && usedDays > expDay3) { stock3 = 0; expired3 += 1; }
    if (stock4 > 0 && usedDays > expDay4) { stock4 = 0; expired4 += 1; }
    if (stock5 > 0 && usedDays > expDay5) { stock5 = 0; expired5 += 1; }
    if (stock6 > 0 && usedDays > expDay6) { stock6 = 0; expired6 += 1; }
    if (stock7 > 0 && usedDays > expDay7) { stock7 = 0; expired7 += 1; }

    /* ---------- เลือกสินค้า (ได้หลายชิ้น) ---------- */
    int cart1 = 0, cart2 = 0, cart3 = 0, cart4 = 0, cart5 = 0, cart6 = 0, cart7 = 0;
    int selecting = 1;

    do {
        int cat = 0;
        printf("\nเลือกประเภทสินค้า: 1=เครื่องดื่ม, 2=ขนม, 0=จบการเลือก: ");
        if (scanf("%d", &cat) != 1) {
            printf("อินพุตไม่ถูกต้อง\n");
            return 1;
        }

        if (cat == 0) {
            break;
        } else if (cat == 1) {
            int ch = 0;
            printf("เครื่องดื่ม: 1)%s  2)%s  3)%s  4)%s  : ", name1, name2, name3, name4);
            if (scanf("%d", &ch) != 1) {
                printf("อินพุตไม่ถูกต้อง\n");
                return 1;
            }
            if (ch == 1) {
                int remain = stock1 - cart1;
                if (remain > 0) { cart1 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name1, cart1); }
                else { if (stock1 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name1); else printf("%s หมดสต็อก/หมดอายุ\n", name1);}            
            } else if (ch == 2) {
                int remain = stock2 - cart2;
                if (remain > 0) { cart2 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name2, cart2); }
                else { if (stock2 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name2); else printf("%s หมดสต็อก/หมดอายุ\n", name2);}            
            } else if (ch == 3) {
                int remain = stock3 - cart3;
                if (remain > 0) { cart3 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name3, cart3); }
                else { if (stock3 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name3); else printf("%s หมดสต็อก/หมดอายุ\n", name3);}            
            } else if (ch == 4) {
                int remain = stock4 - cart4;
                if (remain > 0) { cart4 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name4, cart4); }
                else { if (stock4 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name4); else printf("%s หมดสต็อก/หมดอายุ\n", name4);}            
            } else {
                printf("เมนูไม่ถูกต้อง\n");
            }
        } else if (cat == 2) {
            int ch = 0;
            printf("ขนม: 1)%s  2)%s  3)%s  : ", name5, name6, name7);
            if (scanf("%d", &ch) != 1) {
                printf("อินพุตไม่ถูกต้อง\n");
                return 1;
            }
            if (ch == 1) {
                int remain = stock5 - cart5;
                if (remain > 0) { cart5 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name5, cart5); }
                else { if (stock5 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name5); else printf("%s หมดสต็อก/หมดอายุ\n", name5);}            
            } else if (ch == 2) {
                int remain = stock6 - cart6;
                if (remain > 0) { cart6 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name6, cart6); }
                else { if (stock6 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name6); else printf("%s หมดสต็อก/หมดอายุ\n", name6);}            
            } else if (ch == 3) {
                int remain = stock7 - cart7;
                if (remain > 0) { cart7 += 1; printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", name7, cart7); }
                else { if (stock7 > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", name7); else printf("%s หมดสต็อก/หมดอายุ\n", name7);}            
            } else {
                printf("เมนูไม่ถูกต้อง\n");
            }
        } else {
            printf("เมนูไม่ถูกต้อง\n");
        }

        printf("เลือกต่อหรือไม่? (1=ต่อ, 0=จบการเลือก): ");
        if (scanf("%d", &selecting) != 1) {
            printf("อินพุตไม่ถูกต้อง\n");
            return 1;
        }
    } while (selecting == 1);

    /* สรุปรายการที่เลือก และคำนวณยอดรวม */
    int total = 0;
    int hasItem = 0;
    printf("\n=== รายการสินค้าในตะกร้า ===\n");

    if (cart1 > 0) { int line = cart1 * price1; printf(" - %s x %d = %d บาท\n", name1, cart1, line); total += line; hasItem = 1; }
    if (cart2 > 0) { int line = cart2 * price2; printf(" - %s x %d = %d บาท\n", name2, cart2, line); total += line; hasItem = 1; }
    if (cart3 > 0) { int line = cart3 * price3; printf(" - %s x %d = %d บาท\n", name3, cart3, line); total += line; hasItem = 1; }
    if (cart4 > 0) { int line = cart4 * price4; printf(" - %s x %d = %d บาท\n", name4, cart4, line); total += line; hasItem = 1; }
    if (cart5 > 0) { int line = cart5 * price5; printf(" - %s x %d = %d บาท\n", name5, cart5, line); total += line; hasItem = 1; }
    if (cart6 > 0) { int line = cart6 * price6; printf(" - %s x %d = %d บาท\n", name6, cart6, line); total += line; hasItem = 1; }
    if (cart7 > 0) { int line = cart7 * price7; printf(" - %s x %d = %d บาท\n", name7, cart7, line); total += line; hasItem = 1; }

    printf("รวมราคาสินค้า: %d บาท\n", total);









    if (!hasItem) {
        printf("ไม่มีรายการสินค้า\n");
        /* ไปสรุปท้ายโปรแกรม */
    } else {
        /* ---------- ชำระเงิน ---------- */
        int method = 0;
        printf("\nเลือกวิธีชำระ (1=เงินสด, 2=สแกนจ่าย QR): ");
        if (scanf("%d", &method) != 1) {
            printf("อินพุตไม่ถูกต้อง\n");
            return 1;
        }

        if (method == 2) {
            /* จ่ายด้วย QR */
            int paid = 0;
            do {
                printf("** แสดง QR เพื่อชำระ %d บาท **\n", total);
                printf("โอนสำเร็จหรือไม่? (1=ใช่, 0=ไม่): ");
                if (scanf("%d", &paid) != 1) {
                    printf("อินพุตไม่ถูกต้อง\n");
                    return 1;
                }
                if (paid != 1) {
                    int again = 0;
                    printf("การชำระล้มเหลว ต้องการลองใหม่ไหม? (1=ใช่, 0=ไม่): ");
                    if (scanf("%d", &again) != 1) {
                        printf("อินพุตไม่ถูกต้อง\n");
                        return 1;
                    }
                    if (again != 1) break;
                }
            } while (paid != 1);

            if (paid == 1) {
                /* ปล่อยสินค้าและบันทึกยอดขาย */
                if (cart1 > 0) { sale1 += cart1; stock1 -= cart1; }
                if (cart2 > 0) { sale2 += cart2; stock2 -= cart2; }
                if (cart3 > 0) { sale3 += cart3; stock3 -= cart3; }
                if (cart4 > 0) { sale4 += cart4; stock4 -= cart4; }
                if (cart5 > 0) { sale5 += cart5; stock5 -= cart5; }
                if (cart6 > 0) { sale6 += cart6; stock6 -= cart6; }
                if (cart7 > 0) { sale7 += cart7; stock7 -= cart7; }
                printf("ชำระเงินสำเร็จ! รับสินค้าทั้งหมดเรียบร้อย\n");
            } else {
                printf("ยกเลิกรายการชำระเงิน\n");
            }

        } else if (method == 1) {
            /* เงินสด: รับจำนวนธนบัตร/เหรียญที่ลูกค้าใส่เข้ามา */
            int in1000 = 0, in500 = 0, in100 = 0, in50 = 0, in20 = 0;
            int in10 = 0, in5 = 0, in2 = 0, in1 = 0;
            int inserted = 0;

            printf("\nใส่จำนวนแบงก์ที่ชำระเข้ามา\n");
            printf("แบงก์ 1000 บาท : "); if (scanf("%d", &in1000) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in1000 < 0) in1000 = 0; inserted += in1000 * 1000;
            printf("แบงก์ 500 บาท  : "); if (scanf("%d", &in500 ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in500  < 0) in500  = 0; inserted += in500  * 500;
            printf("แบงก์ 100 บาท  : "); if (scanf("%d", &in100 ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in100  < 0) in100  = 0; inserted += in100  * 100;
            printf("แบงก์ 50 บาท   : "); if (scanf("%d", &in50  ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in50   < 0) in50   = 0; inserted += in50   * 50;
            printf("แบงก์ 20 บาท   : "); if (scanf("%d", &in20  ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in20   < 0) in20   = 0; inserted += in20   * 20;

            printf("ใส่จำนวนเหรียญที่ชำระเข้ามา\n");
            printf("เหรียญ 10 บาท  : "); if (scanf("%d", &in10  ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in10   < 0) in10   = 0; inserted += in10   * 10;
            printf("เหรียญ 5 บาท   : "); if (scanf("%d", &in5   ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in5    < 0) in5    = 0; inserted += in5    * 5;
            printf("เหรียญ 2 บาท   : "); if (scanf("%d", &in2   ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in2    < 0) in2    = 0; inserted += in2    * 2;
            printf("เหรียญ 1 บาท   : "); if (scanf("%d", &in1   ) != 1) { printf("อินพุตไม่ถูกต้อง\n"); return 1; } if (in1    < 0) in1    = 0; inserted += in1    * 1;

            if (inserted < total) {
                printf("ยอดเงินไม่พอ (ใส่ %d บาท ต้องการ %d บาท) ยกเลิกรายการและคืนเงิน\n", inserted, total);
            } else {

                
                //คำนวณยอดเงินทอน//
                int change = inserted - total;

                /* เติมเงินที่ลูกค้าใส่เข้ามาในคลังของตู้ (ชั่วคราว) */
                int t1000 = cnt1000 + in1000;
                int t500  = cnt500  + in500;
                int t100  = cnt100  + in100;
                int t50   = cnt50   + in50;
                int t20   = cnt20   + in20;
                int t10   = cnt10   + in10;
                int t5    = cnt5    + in5;
                int t2    = cnt2    + in2;
                int t1    = cnt1    + in1;

                if (change == 0) {
                    /* ไม่ต้องทอน: commit เติมเงินเข้าตู้, ตัดสต็อก, บันทึกยอดขาย */
                    cnt1000 = t1000; cnt500 = t500; cnt100 = t100; cnt50 = t50; cnt20 = t20;
                    cnt10 = t10; cnt5 = t5; cnt2 = t2; cnt1 = t1;

                    if (cart1 > 0) { sale1 += cart1; stock1 -= cart1; }
                    if (cart2 > 0) { sale2 += cart2; stock2 -= cart2; }
                    if (cart3 > 0) { sale3 += cart3; stock3 -= cart3; }
                    if (cart4 > 0) { sale4 += cart4; stock4 -= cart4; }
                    if (cart5 > 0) { sale5 += cart5; stock5 -= cart5; }
                    if (cart6 > 0) { sale6 += cart6; stock6 -= cart6; }
                    if (cart7 > 0) { sale7 += cart7; stock7 -= cart7; }

                    printf("รับชำระเงินสดพอดี ไม่ต้องทอน\n");
                } else {
                    /* พยายามทอนแบบ greedy ด้วยคลังชั่วคราว */
                    int tmpChange = change;

                    while (tmpChange >= 1000 && t1000 > 0) { tmpChange -= 1000; t1000--; }
                    while (tmpChange >= 500  && t500  > 0) { tmpChange -= 500;  t500--;  }
                    while (tmpChange >= 100  && t100  > 0) { tmpChange -= 100;  t100--;  }
                    while (tmpChange >= 50   && t50   > 0) { tmpChange -= 50;   t50--;   }
                    while (tmpChange >= 20   && t20   > 0) { tmpChange -= 20;   t20--;   }
                    while (tmpChange >= 10   && t10   > 0) { tmpChange -= 10;   t10--;   }
                    while (tmpChange >= 5    && t5    > 0) { tmpChange -= 5;    t5--;    }
                    while (tmpChange >= 2    && t2    > 0) { tmpChange -= 2;    t2--;    }
                    while (tmpChange >= 1    && t1    > 0) { tmpChange -= 1;    t1--;    }

                    if (tmpChange == 0) {
                        /* ทอนได้พอดี: commit คลังเงิน + ตัดสต็อก + บันทึกยอดขาย */
                        cnt1000 = t1000; cnt500 = t500; cnt100 = t100; cnt50 = t50; cnt20 = t20;
                        cnt10 = t10; cnt5 = t5; cnt2 = t2; cnt1 = t1;

                        if (cart1 > 0) { sale1 += cart1; stock1 -= cart1; }
                        if (cart2 > 0) { sale2 += cart2; stock2 -= cart2; }
                        if (cart3 > 0) { sale3 += cart3; stock3 -= cart3; }
                        if (cart4 > 0) { sale4 += cart4; stock4 -= cart4; }
                        if (cart5 > 0) { sale5 += cart5; stock5 -= cart5; }
                        if (cart6 > 0) { sale6 += cart6; stock6 -= cart6; }
                        if (cart7 > 0) { sale7 += cart7; stock7 -= cart7; }

                        printf("รับชำระเงินสด และทอนเงิน %d บาท เรียบร้อย\n", change);
                    } else {
                        /* ทอนไม่ได้: ยกเลิกรายการ และคืนเงิน */
                        printf("ขออภัย ตู้ไม่สามารถทอนเงินให้พอดี (ต้องทอน %d บาท)\n", change);
                        printf("กรุณาเลือกชำระแบบอื่น หรือยกเลิกรายการ\n");
                    }
                }
            }
        } else {
            printf("วิธีชำระไม่ถูกต้อง\n");
        }
    }

    /* ---------- สรุปผลท้ายโปรแกรม ---------- */
    printf("\n=== สรุปยอดขายสินค้า ===\n");
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name1, sale1, stock1, expired1);
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name2, sale2, stock2, expired2);
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name3, sale3, stock3, expired3);
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name4, sale4, stock4, expired4);
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name5, sale5, stock5, expired5);
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name6, sale6, stock6, expired6);
    printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n", name7, sale7, stock7, expired7);

    /* สรุปยอดเงินคงเหลือในตู้ + แสดงจำนวนธนบัตร/เหรียญ */
    int machineTotal = 0;
    machineTotal += 1000 * cnt1000;
    machineTotal += 500  * cnt500;
    machineTotal += 100  * cnt100;
    machineTotal += 50   * cnt50;
    machineTotal += 20   * cnt20;
    machineTotal += 10   * cnt10;
    machineTotal += 5    * cnt5;
    machineTotal += 2    * cnt2;
    machineTotal += 1    * cnt1;

    printf("\n=== เงินคงเหลือในตู้ (รวม %d บาท) ===\n", machineTotal);
    printf("ธนบัตร: ");
    if (cnt1000 > 0) printf("1000บาท:%d  ", cnt1000); else printf("1000บาท:หมด  ");
    if (cnt500  > 0) printf("500บาท:%d  ",  cnt500 ); else printf("500บาท:หมด  ");
    if (cnt100  > 0) printf("100บาท:%d  ",  cnt100 ); else printf("100บาท:หมด  ");
    if (cnt50   > 0) printf("50บาท:%d  ",   cnt50  ); else printf("50บาท:หมด  ");
    if (cnt20   > 0) printf("20บาท:%d  ",   cnt20  ); else printf("20บาท:หมด  ");

    printf("\nเหรียญ:  ");
    if (cnt10   > 0) printf("10บาท:%d  ",   cnt10  ); else printf("10บาท:หมด  ");
    if (cnt5    > 0) printf("5บาท:%d  ",    cnt5   ); else printf("5บาท:หมด  ");
    if (cnt2    > 0) printf("2บาท:%d  ",    cnt2   ); else printf("2บาท:หมด  ");
    if (cnt1    > 0) printf("1บาท:%d  ",    cnt1   ); else printf("1บาท:หมด  ");

    printf("\n");
    return 0;
}
