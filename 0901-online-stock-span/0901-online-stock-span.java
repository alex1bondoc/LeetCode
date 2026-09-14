class StockSpanner {
    Stack<int[]> st= new Stack<>();
    public StockSpanner() {
        
    }
    
    public int next(int price) {
        int span = 1;
        while (st.size() > 0 && st.peek()[1] <= price) {
            span += st.peek()[0];
            st.pop();

        }
        st.push(new int[]{span, price});
        return span;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */