func solution(wallpaper []string) []int {
    lux, luy, rdx, rdy := len(wallpaper), len(wallpaper[0]), -1, -1
    for x,wall := range wallpaper{
        for y,w := range wall{
            if w=='#'{
                if lux > x{
                    lux = x
                }
                if luy > y{
                    luy = y
                }
                if rdx < x{
                    rdx = x
                }
                if rdy <y{
                    rdy = y
                }
            }
        }
    }
    return []int{lux,luy,rdx+1,rdy+1}
}