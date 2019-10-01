
public class Lab6 {
    public static void main(String[] args) {
        Stock stock = new Stock("ORCL", "Oracle Corporation");
        stock.previousClosingPrice = 34.5;
        stock.currentPrice = 34.35;
        System.out.println(stock.getChangePercent());
    }
}

class Stock {
    String symbol;
    String name;
    Double previousClosingPrice;
    Double currentPrice;

    Stock() {
    }

    Stock(String symbol, String name) {
        this.symbol = symbol;
        this.name = name;
    }

    Double getChangePercent() {
        return (currentPrice - previousClosingPrice) / previousClosingPrice * 100;
    }
}