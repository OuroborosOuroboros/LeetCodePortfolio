class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> newList = Collections.<Integer>emptyList();
        if(tomatoSlices % 2 != 0){
            return newList;
        }
        int jumboBurgers = (tomatoSlices-2*cheeseSlices)/2;
        int smallBurgers = cheeseSlices - jumboBurgers;
        if(jumboBurgers<0 || smallBurgers<0){
            return newList;
        }
        List<Integer> total = new ArrayList<>();
        total.add(0, jumboBurgers);
        total.add(1, smallBurgers);

        return total;
    }
}
